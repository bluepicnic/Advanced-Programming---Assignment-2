#include "../Headers/headers.h"

Player::Player()
{
  parseFile(mPlayerBoards, mFleet); //all types of player classes need to initalise their private members using the configurations from the input file.
  
}

Player::~Player()
{
  
}

void Player::deployBoat()
{
  
}


void Player::deployBoats(int remainingBoats)
{

}

void Player::deployMines()
{

}


Coordinates Player::selectTarget()
{
  return {9, 1};
}


void Player::displayBoards()
{
  mPlayerBoards[0].displayBoard(); //shipboard
}
        
void Player::fleetStatus()
{
  ui_boatStatusColTitles();
  for (auto &it : mFleet) {
    it.reportStatus();
  }

  cout << endl << endl;
  ui_saveCursorPos();
  
}

string Player::sayName()
{
  return mPlayerName;
}