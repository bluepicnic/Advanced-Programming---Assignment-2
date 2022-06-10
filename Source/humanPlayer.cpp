#include "../Headers/headers.h"

HumanPlayer::HumanPlayer()
{
  cout << "Please enter your name" << endl;
  mPlayerName = declarePlayerName(); //set player name through input 
}
          
HumanPlayer::~HumanPlayer()
{
  
}

bool HumanPlayer::isHuman()
{
  return true;
}

vector<Coordinates> HumanPlayer::selectTarget(GameType gameMode, int numShots)
{ 
  vector<Coordinates> manualTargets;
  vector<string> provisTargets;
  int boardWidth = mPlayerBoards[0].getWidth();
  int boardHeight = mPlayerBoards[0].getHeight();
  bool targetCommand = false;
  string targetSelection = "";
  regex gmRegExp = (isSalvoGT(gameMode) == true) ? regex_Salvo_Targeting : regex_Targeting;
  

  while (targetCommand != true) {
    targetSelection = getLineString(gmRegExp, invalid_Placement_Command);

    if (isSalvoGT(gameMode) == true) {
      provisTargets = splitSalvoShots(targetSelection, provisTargets);
    } else provisTargets.push_back(targetSelection);
    
    for(int i = 0; i < provisTargets.size(); i++) {
      provisTargets[i] = convertToUpper(provisTargets[i]);
      manualTargets.push_back(splitCoords(provisTargets[i]));

      //check if coord is in bounds, hasn't been previously targeted and player has enough shots left to complete the action
      if(isInBounds(manualTargets[i], boardWidth, boardHeight) && previouslyTargeted(manualTargets[i]) == false && manualTargets.size() <= numShots) {
      //check if coords have been previously selected 
        targetCommand = true;
        
      } else {
        targetCommand = false;
        manualTargets.clear();
        provisTargets.clear();
        break;
      }
    }
  }  
  return manualTargets;
}

string HumanPlayer::declarePlayerName()
{
   //temporary string to store value, don't want to put into member variable without checking it's valid
  ui_saveCursorPos();
    //check all is ok using input parser()
  string playerAlias = getLineString(regex_Alphanumeric, "That name is invalid, please only use alphanumeric characters: ");
  

  return playerAlias;
}
