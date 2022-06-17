#pragma once

class AIPlayer : 
  public Player {
    public:
      AIPlayer(int playerNo);
      ~AIPlayer();
      bool isHuman(); //check if an AI player is human, which isn't. Polymorphic function shared with AI player
      vector<Coordinates> selectTarget(GameType gm, int numShots); //select target randomly
          
};