#pragma once //include header only once

class Game {
  public:
        Game(int menuSelection); //player instances cannot be accessed outside the class, so must alter using functions within the game class. Must pass menuSelection through constructor to generatePlayers. 
        ~Game(); //destroy player objects when current game is no longer needed
        void setup(); //used to set up the game board and place boats, using player input
        void playGame(); //contains full game loop
        void swapTurn(); //used to change and access mCurrentPlayer and mInactive player to determine which player's variables should be used
        string gameType(); //used to get the chosen game type
        

  private:
        Player* generatePlayers(int selection, int index); //Use a factory of sorts to return a new human or computer player instance, depending on menu selection
        GameType selectGameType(int selection);
        Player* mPlayers [num_Players]; //Only ever two players in a game of battleship
        int mCurrentPlayer; //the player currently taking their turn, represented by a number in order to access a specific array index
        int mInactivePlayer; //the player being targeted by enemy fire, uses a number to access the correct player's boards when updating
        GameState mGameState; //the phase the game is currently in
        GameType mGameType; //the type of game being played, chosen by the player on start up
};