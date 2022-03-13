//only include file once
#pragma once 

void parseFile(Board boards[], vector<Ship> &ships); //analyze values from adaship_config.ini
vector<string> extractFileParameters(string toExtract, char delimiter); //separate values from each line of the config file based on a supplied delimiter