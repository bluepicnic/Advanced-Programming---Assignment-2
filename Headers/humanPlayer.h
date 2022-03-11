#pragma once 
#include "player.h"

class HumanPlayer : 
  public Player {
    public:
      HumanPlayer(); //use constructor to set name 
      ~HumanPlayer();
      bool isHuman(); //identify player as a human
      Coordinates selectTarget(int maxWidth, int maxHeight); //manually select a target based on input

    private:
      string declarePlayerName();
};
