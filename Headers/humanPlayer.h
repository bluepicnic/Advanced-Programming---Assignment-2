#pragma once 
#include "player.h"

class HumanPlayer : 
  public Player {
    public:
      HumanPlayer(); 
      ~HumanPlayer();
      bool isHuman(); //identify player as a human
      vector<Coordinates> selectTarget(GameType gameMode, int numShots); //manually select a target based on input

    private:
      string declarePlayerName(); //only used when creating a player
};
