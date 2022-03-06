#pragma once

class AIPlayer : 
  public Player {
    public:
          AIPlayer(int playerNo);
          ~AIPlayer();
          void deployBoats();
          Coordinates selectTarget();
          Space* rootNode; 
          
    private:
          Coordinates mPreviousTarget;
          Direction mSearchDirection;
};