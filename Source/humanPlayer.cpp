#include "../Headers/headers.h"

HumanPlayer::HumanPlayer()
{
  cout << "Please enter your name" << endl;
  mPlayerName = declarePlayerName(); //set player name through input
  
}
          
HumanPlayer::~HumanPlayer()
{
  
}

bool HumanPlayer::isHuman()
{
  return true;
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
   //temporary string to store value, don't want to put into member variable without checking it's valid
  ui_saveCursorPos();
    //check all is ok using input parser()
  string playerAlias = getLineString(regex_Alphanumeric, "That name is invalid, please only use alphanumeric characters: ");
  

  return playerAlias;
}
