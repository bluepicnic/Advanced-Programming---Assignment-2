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
  vector <Coordinates> provisionalLoc; 
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
        int column = 0; 
        int row = 0;
        Board tmpBoard = mPlayerBoards[0]; //store shipboard in case we wish to revert changes
        for (int i = 0; i < mFleet[boatID].reportSize(); i++) {
          
          //check if each coordinate is occupied
          if(mPlayerBoards[0].isOccupied({targetPos.rowPos + row, targetPos.colPos + column}) == false) {
            
            mPlayerBoards[0].updateBoard({targetPos.rowPos + row, targetPos.colPos + column}, SpaceState::Occupied );
            provisionalLoc.push_back({targetPos.rowPos + row, targetPos.colPos + column});
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
          return deployment;
        }
        //if not, accept
        deployment = true;
        mFleet[boatID].updateLocation(provisionalLoc);
        
        
      } 
    }
  }
  
  return deployment;
}


void Player::deployBoats(int remainingBoats)
{

}

void Player::deployMines()
{

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
    it.reportStatus();
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
}