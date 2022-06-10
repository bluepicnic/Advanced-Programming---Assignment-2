#include "../Headers/headers.h"

vector<string> multiShot(string &recur, vector<string> &theList);

void mainMenu()
{
  vector<string> aaaaaa = {};
  string ooooh = "aa11bb22cc33";
  aaaaaa = multiShot(ooooh, aaaaaa);
  
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




//recursive salvo text function


vector<string> multiShot(string &recur, vector<string> &theList) {
  
  string coord = "";
  for (int i = 0; i < 2; i++) {
    string otherCharType = (i == 0) ? numbers : letters;

    size_t strStart = recur.find(recur.front()); //
    size_t strEnd = recur.find_first_of(otherCharType);

    coord += recur.substr(strStart, strEnd);
    if (strEnd > recur.size()) {
      strEnd = recur.size();
    }
    recur = removeLeadTrailSpaces(recur);
    recur = recur.substr(strEnd);
    
  }
  
  theList.push_back(coord);

  
  
  cout << coord << endl;
  cout << recur << endl;

  if (!(recur == "")) {
    return multiShot(recur, theList);
  } 
  
  return theList;
  
}
