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
  Coordinates manualTarget = {};
  int boardWidth = mPlayerBoards[0].getWidth();
  int boardHeight = mPlayerBoards[0].getHeight();
  bool targetCommand = false;
  string boatSelection = "";

  while (targetCommand != true) {
    boatSelection = getLineString(regex_Targeting, invalid_Placement_Command);
    boatSelection = convertToUpper(boatSelection);
    manualTarget = splitCoords(boatSelection);

    //check if coord is in bounds
    if(manualTarget.colPos < boardWidth && manualTarget.rowPos < boardHeight) {
    //check if coords have been previously selected 
      if (previouslyTargeted(manualTarget) == false) {
        targetCommand = true;
      }
    } else {
      targetCommand = false;
    }
  }
  
  
  

  return manualTarget;
}

string HumanPlayer::declarePlayerName()
{
   //temporary string to store value, don't want to put into member variable without checking it's valid
  ui_saveCursorPos();
    //check all is ok using input parser()
  string playerAlias = getLineString(regex_Alphanumeric, "That name is invalid, please only use alphanumeric characters: ");
  

  return playerAlias;
}
