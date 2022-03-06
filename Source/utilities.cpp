#include "../Headers/headers.h"

//unsure what comes under utilities 

string getSingleKeyInput()
{
  char buf = 0;
  string rtnStr = "";
  struct termios old = {0};

  if (tcgetattr(0, &old) < 0) {
    perror("tcsetattr()");
  }

  old.c_lflag &= ~ICANON;
  old.c_lflag &= ~ECHO;
  old.c_cc[VMIN] = 1;
  old.c_cc[VTIME] = 0; 

  if (tcsetattr(0, TCSANOW, &old) < 0) {
    perror("tcsetattr ICANON");
  }

  if (read(0, &buf, 1) < 0) {
    perror ("read()");
  }
  rtnStr.push_back(buf);
  old.c_lflag |= ICANON;
  old.c_lflag |= ECHO;

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
    cout << console_Move_Cursor_Up << error << endl;
    if (isValid == true) {
      cout << console_Move_Cursor_Up << clear_Console_Line;
    }
  }
  
  return input;
}



string convertToLetter(int numToConvert) 
{
  string reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
    cout << clear_Console_Line <<  error << ": ";
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
  size_t idNoPos = command.find_first_of("123456789"); //boat ID will always be the first segement of a boat placement command
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

Coordinates splitCoords(string coords) 
{
  
}