#include "../Headers/headers.h"

//Check all inputs using functions here


bool validateString(string userInput, regex validation, string errorMessage) //check if string matches a particular regex pattern
{
  if (regex_match(userInput, validation)) {
    return true;
  }
  else {
    cout << console_Move_Cursor_Up << errorMessage << endl;
    return false;
  }
}