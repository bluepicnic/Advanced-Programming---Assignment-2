#include "../Headers/headers.h"

//unsure what comes under utilities 

string getSingleKeyInput() //get input from a single key upon key release
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
  old.c_lflag |= ICANON; //reset parameters
  old.c_lflag |= ECHO;

  //reset parameters once output is "transmitted"
  if (tcsetattr(0, TCSADRAIN, &old) < 0) {
    perror ("tcsetattr ~ICANON");
  }

  return rtnStr;
}

bool fileExists(string file) //check if the file exists
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

string removeLeadTrailSpaces(string stringToChange) //remove any return characters from a string
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
    isValid = validateString(input, pattern, error); //check single key is valid based on regex
    
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
      remainder = numToConvert % 26; //obtain the remainder when divided by 26
      char ch = ('A' + remainder); //remainder is 0, then the letter is A, otherwise add the remainder
      letters += ch; //append char to final string
      numToConvert /= 26; 
    }
    reverse(letters.begin(), letters.end()); //letters are appended in reverse order
    return letters; 
}

int convertFromLetter(string charsToConvert)  //convert a letter to a number to access board array positions
{
  //assume that string has been capitalised
  int index = 0;
  int ch = 0;
  char current = '-';
  
  for (int i = 0; i < charsToConvert.size(); i++) {
    current = charsToConvert[i]; 
    ch = current - 65; //subract the ascii value that's at the start of the alphabet (capitalised)
    index += ch * pow(26, (charsToConvert.size() - i) - 1); //multiply by an order of 26 (alphabet length) if more than one letter is included, to facilitate larger board sizes
  }

  return index;
}

string getLineString(regex pattern, string error) {
  bool validString = false;
  string inputStr = "";

  while (validString != true) {
    getline(cin, inputStr); 
    validString = validateString(inputStr, pattern, error); //check string validity
    ui_returnCursorPos();
    
    cout << clear_Console_Screen_Bottom; //clear screen to the bottom 
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
  

  commands.insert(commands.end(), {idNo,coordinate, orientation}); //push back, for multiple values
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


vector<string> splitSalvoShots(string &com, vector<string> &targets) //recursive function
{
  
  string coord = "";
  for (int i = 0; i < 2; i++) { //coordinates always come in pairs
    string otherCharType = (i == 0) ? numbers : letters; //search for the next instance of a letter/number depending on which term was searched for first

    size_t strStart = com.find(com.front()); //get the start of the remaining string
    size_t strEnd = com.find_first_of(otherCharType); //find the next half of the coordinate

    coord += com.substr(strStart, strEnd);
    if (strEnd > com.size()) { //continue until no further letter/number matches can be found
      strEnd = com.size(); //set to end of the string to avoid errors
    }
    com = removeLeadTrailSpaces(com);
    com = com.substr(strEnd);
    
  }
  targets.push_back(coord);

  if (!(com == "")) {
    return splitSalvoShots(com, targets); //repeat if string isn't empty
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