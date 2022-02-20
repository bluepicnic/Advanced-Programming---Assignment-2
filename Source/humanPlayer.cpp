#include "../Headers/headers.h"

HumanPlayer::HumanPlayer()
{
  cout << "I'm a human player" << endl;
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
  
}

string HumanPlayer::getPlayerName()
{
  return mPlayerName;
}

string HumanPlayer::declarePlayerName()
{
  //cin player name
  //check all is ok using input parser()
  return "john";
}
