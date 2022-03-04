#pragma once

using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::regex;

string getSingleKeyInput();
string convertToLower(string format);
string removeLeadTrailSpaces(string stringToChange);
string getLineSingleKey(regex pattern, string error);
string convertToLetter(int numToConvert);
string getLineString(regex pattern, string error);