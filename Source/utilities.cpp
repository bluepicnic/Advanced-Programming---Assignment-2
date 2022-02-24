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
   std::transform(format.begin(), format.end(), format.begin(), ::tolower);
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

string getLineSingleKey(regex pattern, string error){
  bool isValid = false;
  string ohNo = "";

  while(isValid != true){ //continue to prompt if input is invalid
    ohNo = getSingleKeyInput(); 
    isValid = validateString(ohNo, pattern, error);
  }
  return ohNo;
}

string convertToLetter(int numToConvert) 
{
  std::string reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string letters = "";
  int remainder = 0;
  cout << "this has run" << numToConvert << "times     ";
  while (--numToConvert >= 0) {
      remainder = numToConvert % 26;
      char ch = ('A' + remainder);
      letters += ch;
      numToConvert /= 26;
    }
    reverse(letters.begin(), letters.end());
    return letters; 
  
}