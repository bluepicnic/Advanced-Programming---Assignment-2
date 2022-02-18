#pragma once

class AIPlayer : 
  public Player {
    public:
          AIPlayer();
          ~AIPlayer();
          void deployBoats();
          Coordinates selectTarget();
          Space* rootNode; 
          
    private:
          Coordinates mPreviousTarget;
          Direction mSearchDirection;
};