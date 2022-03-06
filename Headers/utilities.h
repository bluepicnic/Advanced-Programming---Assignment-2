#pragma once

string getSingleKeyInput();
string convertToLower(string format);
string convertToUpper(string format);
string removeLeadTrailSpaces(string stringToChange);
string getLineSingleKey(regex pattern, string error);
string convertToLetter(int numToConvert);
int convertFromLetter(string charsToConvert); 
string getLineString(regex pattern, string error);
vector <string> separateCommands(string command);
Coordinates splitCoords(string coords);