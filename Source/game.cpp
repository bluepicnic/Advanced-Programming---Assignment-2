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
  for (int i = 0; i < num_Players; i++) { //complete setup loop for both players
    int boatMenuSelection = -1;
    while (boatMenuSelection != 0 && boatMenuSelection != 6) {
      mCurrentPlayer = i;
      mGameState = GameState::Setup;
      
      

      //ai player functionality 
      if(mPlayers[mCurrentPlayer]->isHuman() == false) {
        mPlayers[i]->deployBoats();

        setupDisplay();
        cout << "Press any button to continue, or 0 to exit" << endl;

        string quitOrContinue = getLineSingleKey(regex_Alphanumeric, "ummmmm");
        boatMenuSelection = (quitOrContinue == "0") ? stoi(quitOrContinue) : 6;
      }

      
      //human player functionality only 
      if(mPlayers[mCurrentPlayer]->isHuman() == true) {
        
        setupDisplay();
        boatMenuSelection = ui_displayBoatPlacement(); //output menu options
  
        switch (boatMenuSelection) {
          case 1: {
            //ui stuff
            ui_BoatPlacementPrompt();
            
            //actual placement
            bool validCommand = false;
            
            while (validCommand != true) {
              string boatSelection = getLineString(regex_Board_Setup, invalid_Placement_Command);
              boatSelection = convertToUpper(boatSelection);
              validCommand = mPlayers[i]->deployBoat(boatSelection);
            }
            
            break;
          }
          
          case 2: {
            //need to create custom regex based on the number of boats
            int fleetSize = mPlayers[mCurrentPlayer]->relayFleetSize() - 1;

            regex fleetInputRange = generateMaxBoatRegex(fleetSize);

            ui_BoatSelectionPrompt();
            int shipSelect = stoi(getLineSingleKey(fleetInputRange, invalid_Ship_Selection));
            mPlayers[i]->deployBoat(shipSelect);
            break;
          }
            
          case 3: { //auto-place available 
            mPlayers[i]->deployBoats(BoatStatus::Inactive);
            break;
          }
  
          case 4: {//auto place all
            mPlayers[i]->deployBoats();
            break;
          }
  
          case 5: {
            mPlayers[i]->recallBoats();
            break;//reset
          }
          
          case 6: {//continue if all boats have been placed 
            //check if all boats deployed
            break;
          }
          
          case 0: {
          return;
          }
          
          default: {
            break;
          }
        }
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

  //ai selection
  //generate two numbers
  
  //player input
  //check if input format is correct
  //check if input ranges are correct

  //place into own registerShot function
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
    return new AIPlayer(index);
  }

  //Player 2 will be an AI unless its a multiplayer game 
  if (index == 1 && (selection != 2 && selection != 5 && selection != 8)){
    return new AIPlayer(index);
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

void Game::gameHeader() 
{
  string currentState = "";
  if(mGameState == GameState::Setup) {
    currentState = " game setup";
  }
  else {
    currentState = "'s turn";
  }
  
  ui_clearScreen();
  cout << text_Colour_Cyan; //set colour for title
  cout << gameType() + mPlayers[0]->sayName() + " vs " + mPlayers[1]->sayName() + " | (" + mPlayers[mCurrentPlayer]->sayName() + currentState + ")" << endl; //game title with player names
}

void Game::setupDisplay()
{
  gameHeader(); //display current game info at top of screen
  mPlayers[mCurrentPlayer]->displayBoards(); //output select player boards
  mPlayers[mCurrentPlayer]->fleetStatus(); //output boat statuses
}


void Game::turnDisplay()
{
  
}
