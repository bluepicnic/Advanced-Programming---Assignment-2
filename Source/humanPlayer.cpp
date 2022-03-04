#include "../Headers/headers.h"

HumanPlayer::HumanPlayer()
{
  cout << "Please enter your name" << endl;
  mPlayerName = declarePlayerName(); //set player name through input
  
}
          
HumanPlayer::~HumanPlayer()
{
  
}

void HumanPlayer::deployBoat()
{ 
  bool validCommand = false;

  while (validCommand != true) {
    string boatSelection = getLineString(regex_Board_Setup, "wrong");
    boatSelection = convertToUpper(boatSelection);
    deployBoat(boatSelection);
  }
  
}

bool HumanPlayer::deployBoat(string command)
{
  bool deployment = false;
  //split command into three parts
  vector <string> commands = separateCommands(command);
  int boatID = stoi(commands[0]);
  string coords = commands[1];
  string rowPos = coords.substr(coords.find_first_of("0123456789"));
  //need to convert any characters to numbers
  
  Coordinates targetPos;
  targetPos.colPos = ;

  

  //check if boat ID is valid 
  if (commands[0] <= mFleet.size() - 1 )

    //check if coordinate is in range, depending on orientation 
      //if a boat already exists there, reject
      //if not, accept

  
}
          
int HumanPlayer::recallBoat(int numBoats)
{
  return 1;
}
          
          
Coordinates HumanPlayer::selectTarget()
{
  return {9, 1};
}

string HumanPlayer::getPlayerName()
{
  return mPlayerName;
}

string HumanPlayer::declarePlayerName()
{
  string playerAlias = ""; //temporary string to store value, don't want to put into member variable without checking it's valid
  bool validName = false;

  while (validName != true) {
    //cin player name
    getline(cin, playerAlias);

    //check all is ok using input parser()
    validName = validateString(playerAlias, regex_Alphanumeric, "That name is invalid, please only use alphanumeric characters");
  } 

  return playerAlias;
}
