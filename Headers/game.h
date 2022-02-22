#pragma once //include header only once

class Game {
  public:
        Game(int menuSelection); //player instances are private, so can only access through Game class functions. Must pass menuSelection through constructor to generatePlayers. 
        ~Game();
        void setup();
        void playGame();
        Player* swapTurn();
        string gameType();
        

  private:
        Player* generatePlayers(int selection, int index); //Use a factory of sorts to return a new human or computer player instance, depending on menu selection
        GameType selectGameType(int selection);
        Player* mPlayers [num_Players]; //Only ever two players in a game of battleship
        Player* mcurrentPlayer;
        Player* mInactivePlayer;
        GameState mGameState;
        GameType mGameType;
};