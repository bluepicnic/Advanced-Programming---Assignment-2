#pragma once 
#include "player.h"

class HumanPlayer : 
  public Player {
    
    public:
          HumanPlayer(); //use constructor to set name 
          ~HumanPlayer();
          int recallBoat(int numBoats);
          Coordinates selectTarget();
          string getPlayerName();
    private:
          string declarePlayerName();
          string mPlayerName;
};
