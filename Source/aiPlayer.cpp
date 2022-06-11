#include "../Headers/headers.h"


AIPlayer::AIPlayer(int playerNo)
{
  playerNo++; //number to be used as part of player name, is increased by 1 here to represent a non 0 number (if an AI is the first player)
  stringstream playerNameNo; //use a stringstream to display raw data
  playerNameNo << "Player " << playerNo;
  mPlayerName = playerNameNo.str();
}


AIPlayer::~AIPlayer()
{

}

bool AIPlayer::isHuman() //confirm player is an AI player
{
  return false;
}

vector<Coordinates> AIPlayer::selectTarget(GameType gm, int numShots)
{
  vector <Coordinates> autoTargets;
  for (int i = numShots; i < 0; i--) {
    autoTargets.push_back(Player::autoTarget());
  }
  
  return autoTargets;
}
