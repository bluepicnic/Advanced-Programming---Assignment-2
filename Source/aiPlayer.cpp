#include "../Headers/headers.h"


AIPlayer::AIPlayer(int playerNo)
{
  playerNo++; //number to be used as part of player name, is increased by 1 here to represent a non 0 number (if an AI is the first player)
  stringstream playerNameNo; //use a stringstream to avoid casting
  playerNameNo << "Player " << playerNo;
  mPlayerName = playerNameNo.str();
}


AIPlayer::~AIPlayer()
{

}

bool AIPlayer::isHuman() 
{
  return false;
}

Coordinates AIPlayer::selectTarget()
{
  
  //if we don't have a previous hit, randomly select a target, by calling base class function
  
  //if we've got a hit, search in cardinal directions in this area

  //perform a depth-first search, following each direction until we don't get a hit

  //remember the first place a hit occurred so that we can return to it, if we get hits but reach the end of a given direction

    //in this case we need to travel in the opposite direction from the original place we recorded a hit


  //reset once a ship has sunk 

  return {9, 1};
}
