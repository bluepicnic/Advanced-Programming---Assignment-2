#pragma once 
#include "player.h"

class HumanPlayer : 
  public Player {
    
    public:
          HumanPlayer(); //use constructor to set name 
          ~HumanPlayer();
          void deployBoat(string command);
          int recallBoat(int numBoats);
          Coordinates selectTarget();
          string getPlayerName();
    private:
          string declarePlayerName();
          
};
