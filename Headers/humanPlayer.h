#pragma once 
#include "player.h"

class HumanPlayer : 
  public Player {
    
    public:
          HumanPlayer(); //use constructor to set name 
          ~HumanPlayer();
          void deployBoat(); //polymorphed function 
          bool deployBoat(string command); //used to deploy boats to boards
          int recallBoat(int numBoats); 
          Coordinates selectTarget();
          string getPlayerName();
    private:
          string declarePlayerName();
          
};
