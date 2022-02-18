#include "../Headers/headers.h"

Game::Game(int menuSelection)
{
  for(int p = 0; p < numPlayers; p++)
  {
    mPlayers[p] = generatePlayers(menuSelection, p);
  }
  
}

Game::~Game()
{

}

void Game::setup()
{
   
}

void Game::playGame()
{

}
        
        
Player* Game::swapTurn()
{
  return nullptr;
}

Player* Game::generatePlayers(int selection, int index)
{
   //Player 1 will always be human unless its AI vs AI

  //Player 2 will be an AI unless its a multiplayer game 
} 