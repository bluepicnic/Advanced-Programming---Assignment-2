#pragma once

class AIPlayer : 
  public Player {
    public:
      AIPlayer(int playerNo);
      ~AIPlayer();
      bool isHuman(); //check if an AI player is human, which isn't. Polymorphic function shared with AI player
      Coordinates selectTarget(); //select target randomly initially, or more targeted if we a hit is registered
          
    private:
      Coordinates mPreviousTarget; //used for space pathfinding
      Direction mSearchDirection; //current direction to search when not searching randomly
};