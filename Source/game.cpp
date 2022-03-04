#include "../Headers/headers.h"

vector <string> separateCommands(string command);

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
  for (int i = 0; i < num_Players; ++i) //deallocate the memory used for our player pointers
  {
    delete mPlayers[i];
  }
}

void Game::setup()
{
  int boatMenuSelection = -1;
  
  for (int i = 0; i < num_Players; i++) {
    while (boatMenuSelection != 0 || boatMenuSelection != 6) {
      ui_clearScreen();
      cout << text_Colour_Cyan; //set colour for title
      cout << gameType() + mPlayers[0]->sayName() + " vs " + mPlayers[1]->sayName() << endl; //game title with player names
      
      mPlayers[i]->displayBoards(); //output select player boards
      mPlayers[i]->fleetStatus(); //output boat statuses
  
      //human player functionality only 
      ui_displayBoatPlacement(); //output menu options
      
      int boatMenuSelection = stoi(getLineSingleKey(regex_Menu_Selection, invalid_Menu_Input));
  
      switch (boatMenuSelection) {
        case 1: {
          //ui stuff
          ui_returnCursorPos();
          cout << "\x1b[0J\r";
          cout << "Input a position using the following format: Boat ID, Location, Orientation (1 d4 h): " << endl;
          ui_saveCursorPos();
          
          //actual placement
          bool validCommand = false;
          
          while (validCommand != true) {
            
            string boatSelection = getLineString(regex_Board_Setup, "That command is invalid: please try again");
            boatSelection = convertToUpper(boatSelection);
            validCommand = mPlayers[i]->deployBoat(boatSelection);
          }
          
          break;
        }
        case 2: break;
        default: break;
      
      
        
      }
    }
  }
  
  
  
  

  
}

void Game::playGame()
{
  setup();

  //title

  //ship board output

  //target board output

  //player input
  //check if input format is correct
  //check if input ranges are correct

  //if hit
  //update current player target board and inactive player ship board
  //update ship statuses and health

  //if miss
  //update current player target board
}
        
        
void Game::swapTurn()
{
  
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

  //Player 2 will be an AI unless its a multiplayer game 
  if (index == 1 && (selection != 2 && selection != 5 && selection != 8)){
    return new AIPlayer;
  }
  else if (index == 1) {
    return new HumanPlayer;
  }
  

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

string Game::gameType()
{
  string gameMode = "Regular";
  if (mGameType == GameType::Salvo_1P || mGameType == GameType::Salvo_2P || mGameType == GameType::Salvo_AI) {
    gameMode = "Salvo";
  }
  
  else if (mGameType == GameType::Mines_1P || mGameType == GameType::Mines_2P || mGameType == GameType::Mines_AI) {
    gameMode = "Mines";
  }

  gameMode += " game - ";

  return gameMode;

}
