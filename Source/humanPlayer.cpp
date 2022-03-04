#include "../Headers/headers.h"

HumanPlayer::HumanPlayer()
{
  cout << "Please enter your name" << endl;
  mPlayerName = declarePlayerName(); //set player name through input
  
}
          
HumanPlayer::~HumanPlayer()
{
  
}

          
int HumanPlayer::recallBoat(int numBoats)
{
  return 1;
}
          
          
Coordinates HumanPlayer::selectTarget()
{
  return {9, 1};
}

string HumanPlayer::getPlayerName()
{
  return mPlayerName;
}

string HumanPlayer::declarePlayerName()
{
  string playerAlias = ""; //temporary string to store value, don't want to put into member variable without checking it's valid
  bool validName = false;

  while (validName != true) {
    //cin player name
    getline(cin, playerAlias);

    //check all is ok using input parser()
    validName = validateString(playerAlias, regex_Alphanumeric, "That name is invalid, please only use alphanumeric characters");
  } 

  return playerAlias;
}
