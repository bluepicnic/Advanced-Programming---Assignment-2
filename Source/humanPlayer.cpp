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
    }

    targetCommand = validTarget(manualTargets, numShots, provisTargets);

    if (targetCommand == false) {
      manualTargets.clear();
      provisTargets.clear();
    }
    
  }  
  return manualTargets;
}

bool HumanPlayer::validTarget(vector<Coordinates> targets, int shots, vector<string> targetCommand) {
  int boardWidth = mPlayerBoards[0].getWidth();
  int boardHeight = mPlayerBoards[0].getHeight();

  //Sets only allow the insertion of unique values, if the length is less than the amount of commands we have, the commands aren't uniqie
  set<string> uniqueCommands(targetCommand.begin(), targetCommand.end());

  //Check:
  //player has enough shots left to complete the action
  if(targets.size() > shots) return false;

  //command is unique
  if (uniqueCommands.size() != targetCommand.size()) return false;

  for (auto it : targets) {
    if (isInBounds(it, boardWidth, boardHeight) == false) return false; //coord is in bounds
    if (previouslyTargeted(it) == true) return false; //coord hasn't been previously targeted
  }
        
  return true;
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