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
  
  //place everything from here down into own function splitCoords
  size_t rowStringPos = coords.find_first_of("0123456789");
  size_t colStringPos = coords.find_first_not_of("0123456789");
  string rowPos = coords.substr(rowStringPos);
  string colPos = coords.substr(colStringPos, rowStringPos);

  
  //need to convert any characters to numbers
  
  Coordinates targetPos;
  targetPos.colPos = convertFromLetter(colPos);
  targetPos.rowPos = stoi(rowPos);
  targetPos.rowPos--;


  //check if boat ID is valid 
  if (boatID <= mFleet.size() - 1 ) {
    //reset existing boats
    //check if coordinate is in range, depending on orientation 
    if(targetPos.colPos < mPlayerBoards[0].getWidth() && targetPos.rowPos < mPlayerBoards[0].getHeight()) {
    
      if(orientation == "V" && (targetPos.rowPos + mFleet[boatID].reportSize()) < mPlayerBoards[0].getHeight()) {
        for (int i = 0; i < mFleet[boatID].reportSize(); i++) {
            int help = targetPos.rowPos + i;
            mPlayerBoards[0].updateBoard({help, targetPos.colPos});
        }
        deployment = true;
      } 
        
      else if (orientation == "H" && (targetPos.colPos + mFleet[boatID].reportSize()) < mPlayerBoards[0].getWidth()) {
        deployment = true;
      }
      
    }
      //if a boat already exists there, reject
      //if not, accept
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