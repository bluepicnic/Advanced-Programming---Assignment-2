#pragma once 
#include "player.h"

class HumanPlayer : 
  public Player {
    
    public:
          HumanPlayer(); //use constructor to set name 
          ~HumanPlayer();
          Coordinates selectTarget();
          string getPlayerName();
    private:
          string declarePlayerName();
          
};
