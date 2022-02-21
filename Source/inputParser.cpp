#include "../Headers/headers.h"

//Check all inputs using functions here


bool validateString(string userInput, regex validation, string errorMessage)
{
  if (regex_match(userInput, validation)) {
    return true;
  }
  else {
    cout << errorMessage << endl << endl;
    return false;
  }
}