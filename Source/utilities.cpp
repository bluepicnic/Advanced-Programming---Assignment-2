#include "../Headers/headers.h"

//unsure what comes under utilities 

string getSingleKeyInput()
{
  char buf = 0;
  string rtnStr = "";
  struct termios old = {0};

  //obtain the attributes currently held by the console
  if (tcgetattr(0, &old) < 0) {
    perror("tcsetattr()");
  }

  old.c_lflag &= ~ICANON; //stop processing console content line-by-line
  old.c_lflag &= ~ECHO; //disable echoing typed characters back to the console
  old.c_cc[VMIN] = 1; //how many bytes are read from an impending input
  old.c_cc[VTIME] = 0; //disable time based reading

  //change attributes now
  if (tcsetattr(0, TCSANOW, &old) < 0) {
    perror("tcsetattr ICANON");
  }

  //await input from the console indefinitely until recieved
  if (read(0, &buf, 1) < 0) {
    perror ("read()");
  }
  rtnStr.push_back(buf);
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;

  //reset parameters once output is "transmitted"
  if (tcsetattr(0, TCSADRAIN, &old) < 0) {
    perror ("tcsetattr ~ICANON");
  }

  return rtnStr;
}

bool fileExists(string file)
{
  struct stat buf;
  if(stat(file.c_str(), &buf) == 0)
  {
    return true; 
  }
  return false;
}

string convertToLower(string format)
{
  using std::transform;
  
  transform(format.begin(), format.end(), format.begin(), ::tolower);
  return format;
}

string convertToUpper(string format)
{
  using std::transform;
  
  transform(format.begin(), format.end(), format.begin(), ::toupper);
  return format;
}

string removeLeadTrailSpaces(string stringToChange)
{
  //find the first and last instance of anything that generates whitespace
	size_t firstChar = stringToChange.find_first_not_of(" \t\v\r\n"); 
	size_t lastChar = stringToChange.find_last_not_of(" \t\v\r\n");
	stringToChange = stringToChange.substr(firstChar, lastChar - firstChar + 1);
  return stringToChange;
}

string getLineSingleKey(regex pattern, string error) 
{
  bool isValid = false;
  string input = "";

  while (isValid != true) { //continue to prompt if input is invalid
    input = getSingleKeyInput(); 
    isValid = validateString(input, pattern, error);
    
    if (isValid != true) {
      cout << ui_moveCursorUp(1) << clear_Console_Line << error << endl;
    }
    else {
      ui_returnCursorPos();
      cout << clear_Console_Screen_Bottom;
    }
    
    
  }
  
  return input;
}

string convertToLetter(int numToConvert) 
{
  string letters = "";
  int remainder = 0;
  while (--numToConvert >= 0) {
      remainder = numToConvert % 26;
      char ch = ('A' + remainder);
      letters += ch;
      numToConvert /= 26;
    }
    reverse(letters.begin(), letters.end());
    return letters; 
}

int convertFromLetter(string charsToConvert) 
{
  int index = 0;
  int ch = 0;
  char current = '-';
  for (int i = 0; i < charsToConvert.size(); i++) {
    current = charsToConvert[i]; 
    ch = current - 65;
    index += ch * pow(26, (charsToConvert.size() - i) - 1); //something like this...
  }

  return index;
}

string getLineString(regex pattern, string error) {
  bool validString = false;
  string inputStr = "";

  while (validString != true) {
    getline(cin, inputStr);
    validString = validateString(inputStr, pattern, error);
    ui_returnCursorPos();
    cout << "\x1b[0J\r";
    cout << clear_Console_Line <<  error;
    cin.clear();
    if (validString == true) {
      cout.flush();
    }
  }

  return inputStr;
}

vector <string> separateCommands(string command) 
{
  vector <string> commands; //return commands as list separated by index
  size_t idNoPos = command.find_first_of("0123456789"); //boat ID will always be the first segement of a boat placement command
  size_t startOfCoord = command.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqurstuvwxyz"); //
  size_t orientationPos = command.find_last_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqurstuvwxyz");
  //create separated strings based on the positions of these elements
  string idNo = command.substr(idNoPos, startOfCoord);
  string orientation = command.substr(orientationPos);
  string coordinate = command.substr(startOfCoord, orientationPos - 1);

  //remove any whitespace
  idNo = removeLeadTrailSpaces(idNo);
  coordinate = removeLeadTrailSpaces(coordinate);
  orientation = removeLeadTrailSpaces(orientation);
  

  commands.insert(commands.end(), {idNo,coordinate, orientation});
  return commands;
}

Coordinates splitCoords(string coordsToSplit) 
{
  //find the locations of letters and numbers in a coordinate input
  size_t rowStringPos = coordsToSplit.find_first_of("0123456789");
  size_t colStringPos = coordsToSplit.find_first_not_of("0123456789");

  //separate into two values
  string rowPos = coordsToSplit.substr(rowStringPos);
  string colPos = coordsToSplit.substr(colStringPos, rowStringPos);

  //store in Coordinates object to return
  Coordinates splitCoords;
  splitCoords.colPos = convertFromLetter(colPos);
  splitCoords.rowPos = stoi(rowPos);
  splitCoords.rowPos--; //minus one from numerical side of the input to be in line with numbers for arrays

  return splitCoords;
}

int rollRandomNumber(int max) 
{    std::random_device roll;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(roll()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(0, max);

    return distrib(gen);
}

regex generateMaxBoatRegex(int sizeOfFleet)
{
  stringstream boatRange;
  boatRange << "^[0-" << sizeOfFleet << "]+$";
  regex maxBoat(boatRange.str());
  return maxBoat;
}

//recursive salvo text function


vector<string> splitSalvoShots(string &com, vector<string> &targets) 
{
  
  string coord = "";
  for (int i = 0; i < 2; i++) {
    string otherCharType = (i == 0) ? numbers : letters;

    size_t strStart = com.find(com.front()); //
    size_t strEnd = com.find_first_of(otherCharType);

    coord += com.substr(strStart, strEnd);
    if (strEnd > com.size()) {
      strEnd = com.size();
    }
    com = removeLeadTrailSpaces(com);
    com = com.substr(strEnd);
    
  }
  targets.push_back(coord);

  if (!(com == "")) {
    return splitSalvoShots(com, targets);
  } 
  
  return targets;
}

bool isSalvoGT(GameType currentGM) 
{
  return (currentGM == GameType::Salvo_1P || currentGM == GameType::Salvo_2P || currentGM == GameType::Salvo_AI);
}

bool isInBounds(Coordinates selection, int width, int height)
{
  return (selection.colPos < width && selection.rowPos < height);
}