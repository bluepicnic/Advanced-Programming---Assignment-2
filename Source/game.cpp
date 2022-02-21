#include "../Headers/headers.h"

Game::Game(int menuSelection)
{
  for(int p = 0; p < num_Players; ++p)
  {
     mPlayers[p] = generatePlayers(menuSelection, p);
     //create an array of 2 players, which we do not know whether they will be AI or Human players until they are created. 
  }
  mGameType = selectGameType(menuSelection);
}

Game::~Game()
{
  cout << "Things are being deleted!!" << endl << endl;
  for (int i = 0; i < num_Players; ++i)
  {
    delete mPlayers[i];
  }
}

void Game::setup()
{
   mPlayers[0]->displayBoards();
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
  if (index == 0 && (selection % 3 != 0)) {
    return new HumanPlayer;
  }
  else if (index == 0) {
    return new AIPlayer;
  }

  if (index == 1 && (selection != 2 && selection != 5 && selection != 8)){
    return new AIPlayer;
  }
  else if (index == 1) {
    return new HumanPlayer;
  }
  //Player 2 will be an AI unless its a multiplayer game 

} 

GameType Game::selectGameType(int selection)
{
  
  switch (selection) {
    case 1: return GameType::Regular_1P;
      break;
    case 2: return GameType::Regular_2P;
      break;
    case 3: return GameType::Regular_AI;
      break;
    case 4: return GameType::Salvo_1P;
      break;
    case 5: return GameType::Salvo_2P;
      break;
    case 6: return GameType::Salvo_AI;
      break;
    case 7: return GameType::Mines_1P;
      break;
    case 8: return GameType::Mines_2P;
      break;
    case 9: return GameType::Mines_AI;
      break;
    default: return GameType::Invalid_Game;
    
  }
}