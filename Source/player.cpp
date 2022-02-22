#include "../Headers/headers.h"

Player::Player()
{
  parseFile(mPlayerBoards, mFleet);
  
}

Player::~Player()
{
  
}

void Player::deployBoats()
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
  mPlayerBoards[0].displayBoard();
}
        
void Player::fleetStatus()
{
  
}

string Player::sayName()
{
  return mPlayerName;
}