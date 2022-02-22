#include "../Headers/headers.h"

void mainMenu()
{
  int selection = -1;
  string selectionString;
  do { //outer game loop, all other game functions originate from here
      ui_displayMainMenu(); //display main menu text

      //get a character input from the user and check input is ok
        selection = stoi(getLineSingleKey());   

        if(selection != 0 ) { 
          //only go ahead with game creation if string is valid
          Game newGame(selection);
          newGame.setup();
        }
        
      
  } while (selection != 0); //continue until the user decides to quit
}


