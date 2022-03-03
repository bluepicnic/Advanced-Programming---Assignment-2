#include "../Headers/headers.h"

//File parse functions here
//Check and apply contents of file 

//player base class constructor method -> would be repeated for each player object created 

void parseFile(Board boards[], vector<Ship> &ships) {
   
   //usual file setup, check if exists
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
    while (!configFile.eof()) { //obtain all config information within file
      
      
      getline(configFile, type, ':'); 
      type = convertToLower(type); //ignore case 
      
      if (type == "board")
      {
        char delim = 'a'; //can't initialise a char with a blank character??
        if(line.find('x')) { //look for a lower case 
          delim = 'x';
        }
        else { //just in case the board 
          delim = 'X';
        }
        getline(configFile, line);
        
        parameters = extractFileParameters(line, delim);
        
        boardWidth = stoi(removeLeadTrailSpaces(parameters[0]));
        boardHeight = stoi(removeLeadTrailSpaces(parameters[1]));

        Board help (boardWidth, boardHeight); 

        for (int i = 0; i < num_Boards; i++) {
          boards[i] = help;
        }

      }
      
      if (type == "boat") {
        getline(configFile, line);
        parameters = extractFileParameters(line, ',');

        
        string shipName = removeLeadTrailSpaces(parameters[0]);
        int sizeHealth = stoi(removeLeadTrailSpaces(parameters[1]));
        Ship tmpShip(shipName, sizeHealth, index);
        index++;

        ships.push_back(tmpShip);
      }
    }
  }

  //while not EOF
   //create a ship object
   
   
  //if first line (split.left = board)
   //read first line, grab width and height
   //create board object (pass in width and height)
   //loop per number of boards to setup both boards using constructors 


  //if boat lines (split.left = ship)
  //setup an individual ship
  //push back into vector 
   
   
   

}

//game class 

//either data is extracted and returned

vector<string> extractFileParameters(string toExtract, char delimiter)
{
  vector <string> params; //there could be a variable number of parameters to extract 
  std::stringstream strStream(toExtract); //need a stringstream similar to a file to use getline on
  string temp = "";
  while (getline(strStream, temp, delimiter)) //even if the delimiter is not found, the loop will continue for the remainder of the stringstream, allowing us to return multiple distinct string objects
  {
    params.push_back(temp); //store separated string items to return
  }

  return params;
}