#include "../Headers/headers.h"


bool validateString(string userInput, regex validation, string errorMessage) //check if string matches a particular regex pattern
{
  if (regex_match(userInput, validation)) {
    return true;
  }
  else {
    return false;
  }
}