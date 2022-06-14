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

bool Game::setup()
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

          //continue if any key other than 0 is pressed
          string quitOrContinue = ui_ContinueText();
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
          return false;
          }
          
          default: {
            break;
          }
        }
    }
  }
  return true;
}

void Game::playGame()
{
  bool gameOver = false;
  Coordinates target; //reflect changes to opposing boards
  vector<Coordinates> targets; //capture multiple targets in salvo game mode,  default container for player targeting input 

  vector<string> shotOutcomes; //store outcome text strings 
  int noShots = 1;
  int remainingShots = 0;
  shipCounts oppBoats = {}; //track total & currently deployed ships of the opposing player
  
  bool setupComplete = setup();

  //reset current and inactive player numbers after setup to maintain the player turn order
  mCurrentPlayer = 0;
  mInactivePlayer = 1;
  noShots = calculatePlayerShots(mGameMode); //number of shots allowed per turn depending on game mode
  
  while(gameOver != true && setupComplete == true) {
    //reset every time
    int targetMethod = -1; 
    mGameState = GameState::Firing;
    shotOutcomes.clear(); //remove remaining outcome text from the previous turn
    
    turnDisplay();

    //ai selection
    if (mPlayers[mCurrentPlayer]->isHuman() != true) {
      if (noShots == 0) { 
        targetMethod = 3; //swap turn
      } else {
        targetMethod = 2; //auto fire
      }
    }
    else {
      //display turn menu and take human player input
      targetMethod = ui_displayTargetSelection(mPlayers[mCurrentPlayer]->sayName(), noShots);
    } 

      switch(targetMethod) {
        case 1 : {
          if (noShots > 0) { //menu option does nothing if player is out of shots
            ui_TargetSelectionPrompt();
            targets = mPlayers[mCurrentPlayer]->selectTarget(mGameMode, noShots);

            //loop through collected coordinates from player input
            for (int i = 0; i < targets.size(); i++) {
              shotOutcomes.push_back(registerShot(targets[i])); //register shot result, and collect the outcome string
              noShots--; 
            }
            gameOver = resolutionDisplay(shotOutcomes); //display outcome and resolve game over state, if applicable
          }
          break;
        }
        case 2: {
          if (noShots > 0) { //menu option does nothing if player is out of shots
            for (remainingShots = noShots; remainingShots > 0; remainingShots--) {
              target = mPlayers[mCurrentPlayer]->autoTarget();
              shotOutcomes.push_back(registerShot(target)); //register shot outcome
              noShots--;
            }
            gameOver = resolutionDisplay(shotOutcomes);
          }
          break;
        }
        case 3: {
          if (noShots == 0) {
            mGameState = GameState::Swap_Turn;
            swapTurn();
            noShots = calculatePlayerShots(mGameMode); //recalculate number of shots only when swapping turns
          }
          break;
        }  
        case 0: {
          return;
        }  
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

Player* Game::generatePlayers(int selection, int index) //create a dynamic player, based on game mode 
{
  //Player 1 will always be human unless its AI vs AI
  if (index == 0 && (selection % 3 != 0)) {
    return new HumanPlayer;
  }
  else if (index == 0) {
    return new AIPlayer(index);
  }

  //Player 2 will be an AI unless its a multiplayer game 
  if (index == 1 && (selection != 2 && selection != 5)){
    return new AIPlayer(index);
  }
  else if (index == 1) {
    return new HumanPlayer;
  }

  return NULL;
  
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
    default: return GameType::Invalid_Game;
    
  }
}

string Game::gameType()
{
  string gameMode = "Regular";
  if (isSalvoGT(mGameMode)) { //change game title text depending on the game mode
    gameMode = "Salvo";
  }
  
  gameMode += " game - ";

  return gameMode;

}

void Game::gameHeader() 
{
  //change the text of the game header during setup and normal gameplay
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
  mPlayers[mCurrentPlayer]->displayBoards(shipboard); //output select player boards
  mPlayers[mCurrentPlayer]->fleetStatus(); //output boat statuses
  ui_saveCursorPos(); //Any menu or UI elements on the setup are displayed below this point, save the cursor position to return it here whenever the display changes
}


void Game::turnDisplay()
{
  gameHeader(); //display current game info at top of screen
  mPlayers[mCurrentPlayer]->displayBoards(shipboard); //output select player boards
  mPlayers[mCurrentPlayer]->fleetStatus(); //output boat statuses
  mPlayers[mCurrentPlayer]->displayBoards(targetboard); //output select player boards
  ui_saveCursorPos(); //Any menu or UI elements on the setup are displayed below this point, save the cursor position to return it here whenever the display changes
}

string Game::registerShot(Coordinates target) 
{
  bool occupiedSpace = mPlayers[mInactivePlayer]->isSpaceOccupied(target);
  string resolveText = "";

  stringstream shotInfo;
  shotInfo << mPlayers[mCurrentPlayer]->sayName() << " fires at " << convertToLetter(target.colPos + 1) << target.rowPos + 1; // add 1 to values to represent the real values visible on the board
  
  if (occupiedSpace == true) {
    resolveText = mPlayers[mCurrentPlayer]->acknowledgeShot(targetboard, target, SpaceState::Hit_Boat);
    
    resolveText += mPlayers[mInactivePlayer]->acknowledgeShot(shipboard, target, SpaceState::Hit_Boat);
    
  } else {
    resolveText = mPlayers[mCurrentPlayer]->acknowledgeShot(targetboard, target, SpaceState::Miss);
  }
  
  return (shotInfo.str() + resolveText);
}

bool Game::resolutionDisplay(vector<string> resolutionText)
{
  mGameState = GameState::Resolution; //update game state 
  
  turnDisplay(); //display boards during resolution 
  for (auto it : resolutionText) { //output outcome text
    cout << it << endl << endl;
  }

  //check if shots this turn resulted in the game ending and display the resolution text associated with that
  shipCounts oppBoats = mPlayers[mInactivePlayer]->reportBoatCounts();
    if (oppBoats.shipsAfloat == 0)
    {
      ui_GameOverText(mPlayers[mCurrentPlayer]->sayName(), mPlayers[mInactivePlayer]->sayName());
      mGameState = GameState::End;
      return true;
    }
  return (ui_ContinueText() == "0"); //otherwise continue with gameplay and display relevant text
  
}

int Game::calculatePlayerShots(GameType mode) 
{
  //number of shots during a salvo game are calculated based on the number of ships still active
  int currentBoats = mPlayers[mCurrentPlayer]->reportBoatCounts().shipsAfloat;
  
  if (isSalvoGT(mode)) {   
      return currentBoats;
    }
    else return 1; //only one shot per turn during a normal game
}