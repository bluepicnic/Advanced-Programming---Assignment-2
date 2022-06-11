#include "../Headers/headers.h"

//Check and apply contents of file 

//We want to use this function once per created game and ensure both players recieve identical game setup data

void parseFile(Board boards[], vector<Ship> &ships) 
{   
  string line = "";
  string type = "";
  int boardWidth = 0;
  int boardHeight = 0;
  ifstream configFile(inFile);
  vector <string> parameters;
  int index = 0;

  if (!configFile) { //check if file exists
    cout << "Config file does not exist";
  } 
  else {
    while (!configFile.eof()) { //obtain game configuration info line by line
      getline(configFile, type, ':'); //Each line states the type of setup information it is providing
      type = convertToLower(type); //ignore case 
      
      if (type == "board") //if its the first line of the file, setup type will be board
      {
        char delim = 'a'; //can't initialise a char with a blank character??
        if(line.find('x')) { //look for a lower case 
          delim = 'x';
        }
        else { //just in case the board has an upper case x
          delim = 'X';
        }
        getline(configFile, line); //get remainder of line, we'll separate parameters ourselves
        
        parameters = extractFileParameters(line, delim);
        
        boardWidth = stoi(removeLeadTrailSpaces(parameters[0]));
        boardHeight = stoi(removeLeadTrailSpaces(parameters[1]));

        Board help (boardWidth, boardHeight); //temporary board to set both player boards with

        for (int i = 0; i < num_Boards; i++) {
          boards[i] = help;
        }

      }
      
      if (type == "boat") {
        //get entire line, point of separation in a boat config string of text will always be a comma
        getline(configFile, line);
        parameters = extractFileParameters(line, ',');

        //prepare extracted ship elements for a temporary ship, which we'll add into a player's boat vector
        string shipName = removeLeadTrailSpaces(parameters[0]);
        int sizeHealth = stoi(removeLeadTrailSpaces(parameters[1]));
        Ship tmpShip(shipName, sizeHealth, index);
        index++;

        ships.push_back(tmpShip);
      }
    }
  }
}

vector<string> extractFileParameters(string toExtract, char delimiter)
{
  vector <string> params; //there could be a variable number of elements to extract 
  stringstream strStream(toExtract); //use an individual line of a file to use as a stringstream
  string temp = "";
  while (getline(strStream, temp, delimiter)) {
    //even if the delimiter is not found, the loop will continue for the remainder of the stringstream, allowing us to return multiple distinct string objects
    params.push_back(temp); //store separated string items to return
  }
  return params;
}