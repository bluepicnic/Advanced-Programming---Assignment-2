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

  if (!configFile) {
    cout << "Config file does not exist";
  } 
  else {
    while (!configFile.eof()) {
      Ship tmpShip;
      
      
      getline(configFile, type, ':');
      type = convertToLower(type);
      
      if (type == "board")
      {
        if(line.find('x')) {
          getline(configFile, line, 'x');
        }
        else {
          getline(configFile, line, 'X');
        }
        removeLeadTrailSpaces(line);
        boardWidth = stoi(line);

        getline(configFile, line);
        removeLeadTrailSpaces(line);
        boardHeight = stoi(line);

        Board help (boardWidth, boardHeight); 
        
        for (int i = 0; i < num_Boards; i++)
        {
          boards[i] = help;
        }

      }
      
      if (line == "boat" || line == "Boat")
      {

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