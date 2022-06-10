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
int rollRandomNumber (int max);
regex generateMaxBoatRegex(int sizeOfFleet);
vector<string> splitSalvoShots(string &com, vector<string> &targets);
bool isSalvoGT(GameType currentGM);
bool isInBounds(Coordinates selection, int width, int height);
