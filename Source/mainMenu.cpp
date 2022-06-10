#include "../Headers/headers.h"



void mainMenu()
{
  vector<string> aaaaaa = {};
  string ooooh = "aa11bb22cc33";
  aaaaaa = splitSalvoShots(ooooh, aaaaaa);
  
  int selection = -1; //all valid menu inputs are positive integers, so initialise as a negative
  string selectionString = "";
  do { //outer game loop, all other game functions originate from here
      ui_displayMainMenu(); //display main menu text

      //get a character input from the user and check input is ok
        selection = stoi(getLineSingleKey(regex_Menu_Selection, invalid_Menu_Input));   

        if(selection != 0 ) { 
          //only go ahead with game creation if string is valid
         Game newGame(selection);
          newGame.playGame();
        }
  } while (selection != 0); //continue until the user decides to quit
}

