#include "../Headers/headers.h"

Player::Player()
{
  parseFile(mPlayerBoards, mFleet); //all types of player classes need to initalise their private members using the configurations from the input file.
  
}

Player::~Player()
{
  
}

bool Player::deployBoat(string command) //manually deploy boat with input command
{
  bool deployment = false;

  int width = mPlayerBoards[0].getWidth();
  int height = mPlayerBoards[0].getHeight();
  
  //split user input command into its three components parts 
  vector <string> commands = separateCommands(command); 
  int boatID = stoi(commands[0]);
  string coords = commands[1];
  string orientation = commands[2];
  
  //need to convert any characters to numbers, split whole coordinate input
  Coordinates targetPos = splitCoords(coords); 
  
  //check if boat ID is valid 
  if (boatID > mFleet.size() - 1 ) return deployment;

  //check if initial position to place the boat is valid
  if (isInBounds(targetPos, width, height) == false) return deployment;
    
  //check if coordinate is in range, depending on orientation 
  if((orientation == "V" && (targetPos.rowPos + mFleet[boatID].reportSize()) <= height) || (orientation == "H" && (targetPos.colPos + mFleet[boatID].reportSize()) <= width)) {
    //reset existing boat placement, if already placed
    recallBoat(boatID);
    return deployBoat(boatID, targetPos, orientation);
  } 
  
  return false;
}

void Player::deployBoat(int boatID) //auto-place ship based on 
{
  bool validCoords = false;
  Coordinates randCoords;

  //store these here to avoid writing longhand when calculating array sizes
  int height = mPlayerBoards[0].getHeight() - 1;
  int width = mPlayerBoards[0].getWidth() - 1; 
  
  while (validCoords != true) {
    int orientation = (rollRandomNumber(INT_MAX) % 2 == 0); //randomly roll a number, and select an orientation (using either 1 or 0) based on if the value rolled is odd or even

    //Vertical = 0, Horizontal = 1
    string orientChar = (orientation == 0) ? "V" : "H";

    //we want to only randomly roll a value small enough to fit the full width of a boat on a board given a particular orientation 
    int maxY = (orientChar == "V") ? height : height - mFleet[boatID].reportSize();
    int maxX = (orientChar == "H") ? width : width - mFleet[boatID].reportSize();

    randCoords.colPos = rollRandomNumber(maxY);
    randCoords.rowPos = rollRandomNumber(maxX);

    //always recall the selected boat to avoid placing twice
    recallBoat(boatID);
    validCoords = deployBoat(boatID, randCoords, orientChar); 
  }
}

bool Player::deployBoat(int boatID, Coordinates loc, string orientation)  //update boards and deploy boat
{
  int column = 0; 
  int row = 0;
  
  Board tmpBoard = mPlayerBoards[0]; //store shipboard in case we wish to revert changes
  vector <Coordinates> provisionalLoc;

  //check boat ID is valid
  for (int i = 0; i < mFleet[boatID].reportSize(); i++) {
    //check if coordinate is occupied
    if(mPlayerBoards[shipboard].isOccupied({loc.rowPos + row, loc.colPos + column}) == false) {
      
      mPlayerBoards[shipboard].updateBoard({loc.rowPos + row, loc.colPos + column}, SpaceState::Occupied );
      provisionalLoc.push_back({loc.rowPos + row, loc.colPos + column});
    }
    
    //increment specific counter for a given orientation to the next position along that axis
    if (orientation == "V") {
      row++;
    } else {
      column++;
    }
  }
  
  //if any issues have occured (i.e if any coordinates are already occupied), then we will have deployed to less coordinates than the size of the boat
  if(provisionalLoc.size() < mFleet[boatID].reportSize()) {
    //recall boat if we're unable to place boat in its entirety
    recallBoat(boatID);
    mPlayerBoards[shipboard] = tmpBoard;
    return false;
  }
  //if not, accept and return
  mFleet[boatID].updateLocation(provisionalLoc);
  mFleet[boatID].updateStatus(BoatStatus::Deployed);
  return true;
}


void Player::deployBoats()
{
  for (int i = 0; i < mFleet.size(); i++) {
    deployBoat(i);
  }
}

void Player::deployBoats(BoatStatus statusToDeploy) 
{
  //automatically deploy all boats with a specific status
  for (int i = 0; i < mFleet.size(); i++) {
    if (mFleet[i].reportStatus() == statusToDeploy) {
      deployBoat(i);
    }
  }
}

void Player::displayBoards(int boardNo)
{
  //determine if the board being displayed is the ship or target board
  string boardHeader = (boardNo == 0) ? ship_Board_Header : target_Board_Header;
  cout << text_Colour_Cyan << boardHeader;
  mPlayerBoards[boardNo].displayBoard();
}
        
void Player::fleetStatus()
{
  //display information on all boats in a player's fleet including: id; name; size; current health; and status
  ui_boatStatusColTitles();
  for (auto &it : mFleet) {
    it.vesselStatusReport();
  }

  cout << endl << endl;
  
}

string Player::sayName()
{
  return mPlayerName;
}

void Player::recallBoat(int boatNo)
{
  //reset spaces that were previously occupied 
  vector<Coordinates> boatSpaces = mFleet[boatNo].reportLocation();
  for(auto it : boatSpaces) {
    mPlayerBoards[shipboard].updateBoard(it, SpaceState::Inactive);
  }

  //reset boat values
  mFleet[boatNo].updateLocation({});
  mFleet[boatNo].updateStatus(BoatStatus::Inactive);
}

void Player::recallBoats() 
{
  //recall all boats (wrapper function)
  for (int i = 0; i < mFleet.size(); i++) {
    recallBoat(i);
  }
}

int Player::relayFleetSize() 
{
  return mFleet.size();
}

Coordinates Player::autoTarget() 
{
  Coordinates rolledTarget;
  bool previousTarget = true;
  while (previousTarget != false) {
    rolledTarget.rowPos = rollRandomNumber(mPlayerBoards[targetboard].getWidth() - 1);
    rolledTarget.colPos = rollRandomNumber(mPlayerBoards[targetboard].getHeight() - 1);
    previousTarget = previouslyTargeted(rolledTarget);
  }
  
  return rolledTarget;
}

bool Player::isSpaceOccupied(Coordinates target) 
{
  SpaceState occSpaceState = mPlayerBoards[shipboard].getSpaceStatus(target);
  return occSpaceState == SpaceState::Occupied ? true : false;
  //return mPlayerBoards[shipboard].isOccupied(target);
}

bool Player::previouslyTargeted(Coordinates target)
{
  SpaceState prevTargetState = mPlayerBoards[targetboard].getSpaceStatus(target);
  return prevTargetState == SpaceState::Inactive ? false : true;
  //return (spaces[chkCoords.rowPos][chkCoords.colPos].status == SpaceState::Occupied); 
}

shipCounts Player::reportBoatCounts()
{
  int boatCount = 0;
  int totalBoats = 0;
  
  for (auto it : mFleet) {
    if (it.reportStatus() == BoatStatus::Deployed) {
      boatCount++;
    }
    totalBoats++;
  }

  //return both the total number of boats and how many boats are currently deployed
  return {totalBoats, boatCount};
}

string Player::acknowledgeShot(int board, Coordinates shotTarget, SpaceState acknowledgement)
{
  string ackText = "";
 
  mPlayerBoards[board].updateBoard(shotTarget, acknowledgement); 

  if (acknowledgement != SpaceState::Hit_Boat) return miss_Text; //if a hit is not registered, return miss text

  if (board != shipboard) return hit_Text; //if the board being updated is the ship board, only return hit text

  //otherwise search the player's ships for the current player's targeted coordinate, and display extra text if ship at that position is destroyed
  for (auto& it : mFleet) {
        for (auto lit : it.reportLocation()) {
          if (lit.colPos == shotTarget.colPos && lit.rowPos == shotTarget.rowPos) {
              ackText = it.reportDamageTaken(); //opposition player declares the name of the ship when it is destroyed
              if (ackText != "") return "\n" + mPlayerName + "'s " + ackText + " has been destroyed!";

              else return ackText;
          }
        }
 }
  return "Shot has not been acknowledged"; 
}