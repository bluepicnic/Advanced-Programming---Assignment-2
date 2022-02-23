#include "../Headers/headers.h"


AIPlayer::AIPlayer()
{
  cout << "I'm an AI Player" << endl; 
  mPlayerName = "Player"; //give AI players generic names
}


AIPlayer::~AIPlayer()
{

}

void AIPlayer::deployBoats()
{
  //randomly and automatically place boats 
}


Coordinates AIPlayer::selectTarget()
{
  //randomly select a target

  //if we've got a hit, search in cardinal directions in this area

  //perform a depth-first search, following each direction until we don't get a hit

  //remember the first place a hit occurred so that we can return to it, if we get hits but reach the end of a given direction

    //in this case we need to travel in the opposite direction from the original place we recorded a hit


  //reset once a ship has sunk 

  return {9, 1};
}