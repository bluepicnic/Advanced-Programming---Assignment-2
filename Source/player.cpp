#include "../Headers/headers.h"

Player::Player()
{
  parseFile(mPlayerBoards, mFleet); //all types of player classes need to initalise their private members using the configurations from the input file.
  
}

Player::~Player()
{
  
}

bool Player::deployBoat(string command)
{
  bool deployment = false;
  //split command into three parts
  vector <string> commands = separateCommands(command); 
  int boatID = stoi(commands[0]);
  string coords = commands[1];
  string orientation = commands[2];
  
  //need to convert any characters to numbers, split whole coordinate input
  Coordinates targetPos = splitCoords(coords); 
  
  //check if boat ID is valid 
  if (boatID <= mFleet.size() - 1 ) {
    //check if coordinate is in range, depending on orientation 
    if(targetPos.colPos < mPlayerBoards[0].getWidth() && targetPos.rowPos < mPlayerBoards[0].getHeight()) {
      
      if((orientation == "V" && (targetPos.rowPos + mFleet[boatID].reportSize()) <= mPlayerBoards[0].getHeight()) || 
        (orientation == "H" && (targetPos.colPos + mFleet[boatID].reportSize()) <= mPlayerBoards[0].getWidth())) {
        
      //reset existing boat placement, if already placed
      recallBoat(boatID);
      deployment = deployBoat(boatID, targetPos, orientation);
        
        
      } 
    }
  }
  
  return deployment;
}

void Player::deployBoat(int boatID)
{
  bool validCoords = false;

  //store these here to avoid writing longhand when calculating array sizes
  int height = mPlayerBoards[0].getHeight() - 1;
  int width = mPlayerBoards[0].getWidth() - 1; 

  Coordinates randCoords;

  while (validCoords != true) {
    int orientation = (rollRandomNumber(INT_MAX) % 2 == 0); //0 represents vertical, 1 represent horizontal

    //if vertical we want to only roll a column value small enough to fit a boat vertically
    int maxY = (orientation == 0) ? height : height - mFleet[boatID].reportSize();
    int maxX = (orientation == 1) ? width : width - mFleet[boatID].reportSize();

    randCoords.colPos = rollRandomNumber(maxY);
    randCoords.rowPos = rollRandomNumber(maxX);

    string orientChar = (orientation == 0) ? "V" : "H";

    recallBoat(boatID);
    validCoords = deployBoat(boatID, randCoords, orientChar); 
  }
}

bool Player::deployBoat(int boatID, Coordinates loc, string orientation) 
{
  int column = 0; 
  int row = 0;
  Board tmpBoard = mPlayerBoards[0]; //store shipboard in case we wish to revert changes
  vector <Coordinates> provisionalLoc;
  
  for (int i = 0; i < mFleet[boatID].reportSize(); i++) {
    //check if each coordinate is occupied
    if(mPlayerBoards[0].isOccupied({loc.rowPos + row, loc.colPos + column}) == false) {
      
      mPlayerBoards[0].updateBoard({loc.rowPos + row, loc.colPos + column}, SpaceState::Occupied );
      provisionalLoc.push_back({loc.rowPos + row, loc.colPos + column});
    }
    
    if (orientation == "V") {
      row++;
    } else {
      column++;
    }
  }
  //if any issues have occured (i.e if any coordinates are already occupied), then we will have deployed to less coordinates than the size of the boat
  if(provisionalLoc.size() < mFleet[boatID].reportSize())
  {
    //recall boat if we're unable to place boat in its entirety
    recallBoat(boatID);
    mPlayerBoards[0] = tmpBoard;
    return false;
  }
  //if not, accept
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
  for (int i = 0; i < mFleet.size(); i++) {
    if (mFleet[i].reportStatus() == statusToDeploy) {
      deployBoat(i);
    }
  }
}

Coordinates Player::selectTarget()
{
  return {9, 1};
}


void Player::displayBoards()
{
  mPlayerBoards[0].displayBoard(); //shipboard
}
        
void Player::fleetStatus()
{
  ui_boatStatusColTitles();
  for (auto &it : mFleet) {
    it.vesselStatusReport();
  }

  cout << endl << endl;
  ui_saveCursorPos();
  
}

string Player::sayName()
{
  return mPlayerName;
}

void Player::recallBoat(int boatNo)
{
  vector<Coordinates> boatSpaces = mFleet[boatNo].reportLocation();
  for(auto it : boatSpaces) {
    mPlayerBoards[0].updateBoard(it, SpaceState::Unoccupied);
  }

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