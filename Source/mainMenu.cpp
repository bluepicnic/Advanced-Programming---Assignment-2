#include "../Headers/headers.h"
void convertToLetter(int numToConvert);

void mainMenu()
{
  for (int i = 0; i < (26 * 26) + 26; i++){
    convertToLetter(i);
  }
  
  int selection = -1;
  string selectionString;
  do { //outer game loop, all other game functions originate from here
      ui_displayMainMenu(); //display main menu text

      //get a character input from the user and check input is ok
        selection = stoi(getLineSingleKey(regex_Menu_Selection, invalid_Menu_Input));   

        if(selection != 0 ) { 
          //only go ahead with game creation if string is valid
          Game newGame(selection);
          newGame.setup();
        }
        
      
  } while (selection != 0); //continue until the user decides to quit
}


void convertToLetter(int numToConvert) 
{
  std::string reference = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string letters = "";
  int remainder = 0;
  int inAlpha = numToConvert / 26;
  if (numToConvert >= 0 && inAlpha == 0)
  {
    cout << reference[numToConvert - 1];
  }
  else if (numToConvert > 25)
  {
    numToConvert -= 26;
    while (numToConvert / 26 != 0)
      {
        remainder = (numToConvert % 26) + 1;
        letters.push_back(reference[remainder]);
        numToConvert /= 26;
      }
    letters.push_back(reference[numToConvert]);
  }
  for (auto it = letters.rbegin(); it != letters.rend(); it++){
    cout << *it << " ";
  }
  cout << endl << "\t";
}


//recursive salvo text function
