#include "../Headers/headers.h"

HumanPlayer::HumanPlayer()
{
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
  vector<Coordinates> manualTargets; //stores coordinates after raw strings have been checked
  vector<string> provisTargets; //raw inputs
  
  int boardWidth = mPlayerBoards[0].getWidth();
  int boardHeight = mPlayerBoards[0].getHeight();
  
  bool targetCommand = false;
  string targetSelection = "";
  regex gmRegExp = (isSalvoGT(gameMode) == true) ? regex_Salvo_Targeting : regex_Targeting; //change how firing inputs are validated based on gamemode
  

  while (targetCommand != true) {
    targetSelection = getLineString(gmRegExp, invalid_Placement_Command); //take input

    //need to separate input coordinates during a salvo game
    if (isSalvoGT(gameMode) == true) {
      provisTargets = splitSalvoShots(targetSelection, provisTargets);
    } else provisTargets.push_back(targetSelection); //just the one coordinate otherwise
    
    for(int i = 0; i < provisTargets.size(); i++) {
      provisTargets[i] = convertToUpper(provisTargets[i]);
      manualTargets.push_back(splitCoords(provisTargets[i]));

      //check if coord is in bounds, hasn't been previously targeted and player has enough shots left to complete the action
      if(isInBounds(manualTargets[i], boardWidth, boardHeight) && previouslyTargeted(manualTargets[i]) == false && manualTargets.size() <= numShots) {
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
  
  ui_saveCursorPos();
  cout << name_Prompt << endl;
  //temporary string to store value, don't want to put into member variable without checking it's valid
  string playerAlias = getLineString(regex_Alphanumeric, invalid_Name);
  ui_returnCursorPos();
  cout << clear_Console_Screen_Bottom;
  
  return playerAlias;
}
