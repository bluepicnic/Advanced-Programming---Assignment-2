#include "../Headers/headers.h"

vector <string> separateCommands(string command);

Game::Game(int menuSelection)
{
  for(int p = 0; p < num_Players; ++p)
  {
     mPlayers[p] = generatePlayers(menuSelection, p);
     //create an array of 2 players, which we do not know whether they will be AI or Human players until they are created. 
  }
  mGameMode = selectGameType(menuSelection);
}

Game::~Game()
{
  for (int i = 0; i < num_Players; ++i) //deallocate the memory used for our player pointers
  {
    delete mPlayers[i];
  }
}

void Game::setup()
{
  
  for (int i = 0; i < num_Players; i++) { //complete setup loop for both players
    int boatMenuSelection = -1;
    shipCounts setupBoats = {};
    
    while (boatMenuSelection != 0 && boatMenuSelection != 6) {
      mCurrentPlayer = i;
      mGameState = GameState::Setup;
      setupBoats = mPlayers[i]->reportBoatCounts();

      setupDisplay();
      
      //ai player functionality 
      if(mPlayers[mCurrentPlayer]->isHuman() == false) {
        if (setupBoats.shipsAfloat != setupBoats.totalShips) {
          boatMenuSelection = 4; //AI will always auto-place
        }
        else {
          cout << "Press any button to continue, or 0 to exit" << endl;

          //change this
          string quitOrContinue = getLineSingleKey(regex_Alphanumeric, "ummmmm");
          boatMenuSelection = (quitOrContinue == "0") ? stoi(quitOrContinue) : 6;
        }
        
      }

      
      //human player functionality only 
      if(mPlayers[mCurrentPlayer]->isHuman() == true) {
        boatMenuSelection = ui_displayBoatPlacement(); //output menu options
      }

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
            int fleetSize = setupBoats.totalShips - 1;

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
          
          case 6: {
            //check if all boats deployed
            boatMenuSelection = (setupBoats.shipsAfloat < setupBoats.totalShips) ? -1 : 6;
            //continue if all boats have been placed 
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

void Game::playGame()
{
  bool gameOver = false;
  Coordinates target; //coordinate used to reflect changes to opposing boards
  int noShots = 1;
  int remainingShots = 0;
  shipCounts currentBoats = {}; //track total & currently deployed ships
  shipCounts oppBoats = {};
  
  setup();
  
  while(gameOver != true) {
    mGameState = GameState::Firing;
    swapTurn();
    turnDisplay();

    currentBoats = mPlayers[mCurrentPlayer]->reportBoatCounts();
    
    if (mGameMode == GameType::Salvo_1P || mGameMode == GameType::Salvo_2P || mGameMode == GameType::Salvo_AI) {
    
      noShots = currentBoats.shipsAfloat;
    }

    //ai selection
    //generate two numbers
    if (mPlayers[mCurrentPlayer]->isHuman() != true) {
      target = mPlayers[mCurrentPlayer]->autoTarget();
      registerShot(target);
    }
    else {
      //display turn menu
      cout << endl << "1. Manual Target" << endl;
      cout << endl << "2. Auto Target" << endl;
      //player input
      int targetMethod = stoi(getLineSingleKey(pat_Turn_Menu, invalid_Menu_Input));

      switch(targetMethod) {
        case 1 : {
          ui_TargetSelectionPrompt();
          //target = mPlayers()
            //check if input format is correct
            //check if input ranges are correct
            //check current player's targetboards status for the specific spaces

          target = mPlayers[mCurrentPlayer]->selectTarget();
          registerShot(target);
          break;
          
        }
        case 2: {
          for (int i = 0; i < noShots; i++) {
            target = mPlayers[mCurrentPlayer]->autoTarget();
            registerShot(target);
            break;
          }
          
        }
      }
    }
  
  //place into own registerShot function
    //retrieve defending player's shipboard status for the specific space 
    //if hit
    //update current player target board and inactive player ship board
    //update ship statuses and health
  
    //if miss
    //update current player target board
    getLineSingleKey(regex_Any_Key, "EEEEEEEEEE");
    //swapTurn();
  }
  
  
  
  
}
        
        
void Game::swapTurn()
{
  if(mCurrentPlayer == 0) {
    mCurrentPlayer++;
    mInactivePlayer--;
  }
  else {
    mCurrentPlayer--;
    mInactivePlayer++;
  }
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
  if (mGameMode == GameType::Salvo_1P || mGameMode == GameType::Salvo_2P || mGameMode == GameType::Salvo_AI) {
    gameMode = "Salvo";
  }
  
  else if (mGameMode == GameType::Mines_1P || mGameMode == GameType::Mines_2P || mGameMode == GameType::Mines_AI) {
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
  cout << gameType() + mPlayers[0]->sayName() + " vs " + mPlayers[1]->sayName() + " | (" + mPlayers[mCurrentPlayer]->sayName() + currentState + ")" << endl << endl; //game title with player names
}

void Game::setupDisplay()
{
  gameHeader(); //display current game info at top of screen
  mPlayers[mCurrentPlayer]->displayBoards(0); //output select player boards
  mPlayers[mCurrentPlayer]->fleetStatus(); //output boat statuses
  ui_saveCursorPos(); //Any menu or UI elements on the setup are displayed below this point, save the cursor position to return it here whenever the display changes
}


void Game::turnDisplay()
{
  gameHeader(); //display current game info at top of screen
  mPlayers[mCurrentPlayer]->displayBoards(0); //output select player boards
  mPlayers[mCurrentPlayer]->fleetStatus(); //output boat statuses
  mPlayers[mCurrentPlayer]->displayBoards(1); //output select player boards
  ui_saveCursorPos(); //Any menu or UI elements on the setup are displayed below this point, save the cursor position to return it here whenever the display changes
}

void Game::registerShot(Coordinates target) 
{
  bool occupiedSpace = mPlayers[mInactivePlayer]->isSpaceOccupied(target);
  string resolveText = "";

  stringstream shotInfo;
  shotInfo << mPlayers[mCurrentPlayer]->sayName() << " fires at " << convertToLetter(target.colPos + 1) << target.rowPos + 1;
  
  if (occupiedSpace == true) {
    mPlayers[mCurrentPlayer]->acknowledgeShot(targetboard, target, SpaceState::Hit_Boat);
    
    mPlayers[mInactivePlayer]->acknowledgeShot(shipboard, target, SpaceState::Hit_Boat);
    resolveText = hit_Text;
    
  } else {
    mPlayers[mCurrentPlayer]->acknowledgeShot(targetboard, target, SpaceState::Miss);
    resolveText = miss_Text;
  }
  
  resolutionDisplay(shotInfo.str() + resolveText);
}

void Game::resolutionDisplay(string resolutionText)
{
  turnDisplay();
  //take a vector as a parameter for SALVO
  cout << resolutionText << endl << endl;
}