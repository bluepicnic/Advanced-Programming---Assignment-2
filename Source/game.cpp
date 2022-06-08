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
        else { //once AI deployment is complete
          cout << "Press any button to continue, or 0 to exit" << endl;

          //continue if any key other than 0 is pressed
          string quitOrContinue = getLineSingleKey(regex_Alphanumeric, "ummmmm");
          boatMenuSelection = (quitOrContinue == "0") ? stoi(quitOrContinue) : 6;
        }
        
      }

      
      //human player functionality only 
      if(mPlayers[mCurrentPlayer]->isHuman() == true) {
        boatMenuSelection = ui_displayBoatPlacement(setupBoats.shipsAfloat == setupBoats.totalShips); //output menu options
      }

      //both player types to select from menu cases
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
  int noShots = calculatePlayerShots();
  int remainingShots = 0;
  int targetMethod = -1;
  shipCounts oppBoats = {}; //track total & currently deployed ships of the opposing player
  
  setup();
  swapTurn();
  
  
  while(gameOver != true) {
    mGameState = GameState::Firing;
    
    turnDisplay();

    //ai selection
    //generate two numbers
    if (mPlayers[mCurrentPlayer]->isHuman() != true) {
      target = mPlayers[mCurrentPlayer]->autoTarget();
      registerShot(target);
      targetMethod = 3;
    }
    else {
      //display turn menu and take player input
      targetMethod = ui_displayTargetSelection(noShots == 0);
    } 

      switch(targetMethod) {
        case 1 : {
          if (noShots > 0) {
            ui_TargetSelectionPrompt();
          
            //for (int i = 0; i < noShots; i++)
            target = mPlayers[mCurrentPlayer]->selectTarget();
            registerShot(target);
            noShots--;
            
          }
          break;
        }
        case 2: {
          for (int i = 0; i < noShots; i++) {
            target = mPlayers[mCurrentPlayer]->autoTarget();
            registerShot(target);
            noShots--;
          }
          break;
        }
        case 3: {
          if (noShots == 0) {
            swapTurn();
            noShots = calculatePlayerShots(); //recalculate number of shots only when swapping turns
            break;
          }
          
        }
      }
  
  //FOR SALVO
  //Need to stop turn swapping if shots are remaining
  //otherwise show continue text
  //this will allow some shots to be taken manually
  //include an option for a single shot and all remaining shots
    
    
    //swapTurn();
    oppBoats = mPlayers[mInactivePlayer]->reportBoatCounts();
    if (oppBoats.shipsAfloat == 0)
    {
      gameOver = true;
      ui_GameOverText(mPlayers[mCurrentPlayer], mPlayers[mInactivePlayer]);
    }
  
    
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
    resolveText = mPlayers[mCurrentPlayer]->acknowledgeShot(targetboard, target, SpaceState::Hit_Boat);
    
    resolveText += mPlayers[mInactivePlayer]->acknowledgeShot(shipboard, target, SpaceState::Hit_Boat);
    
  } else {
    resolveText = mPlayers[mCurrentPlayer]->acknowledgeShot(targetboard, target, SpaceState::Miss);
  }
  
  resolutionDisplay(shotInfo.str() + resolveText);
}

void Game::resolutionDisplay(string resolutionText)
{
  turnDisplay();
  //take a vector as a parameter for SALVO
  cout << resolutionText << endl << endl;
  cout << "Press any key to confirm" << endl;
  getLineSingleKey(regex_Any_Key, "EEEEEEEEEE");
}

int Game::calculatePlayerShots() 
{
  int currentBoats = mPlayers[mCurrentPlayer]->reportBoatCounts().shipsAfloat;
  
  if (mGameMode == GameType::Salvo_1P || mGameMode == GameType::Salvo_2P || mGameMode == GameType::Salvo_AI) {  
      return currentBoats;
    }
    else return 1;
}