#pragma once //include header only once

class Game {
  public:
    Game(int menuSelection); //player values are private, so can only be accessed in their respective class. Upon creation, we'll pass relevant values through from the game class 
    ~Game(); //destroy player objects when current game is no longer needed
    bool setup(); //used to set up the game board and place boats, using player input to decide
    void playGame(); //contains full game loop
    void swapTurn(); //used to change and swap current and inactive players
    string gameType(); //used to get the chosen game type
    void registerShot(Coordinates target); //resolve chosen player target when firing
    void gameHeader(); //display information about the current game (type, players, current player etc)
    void setupDisplay(); //display ui elements and respective player boards during setup
    void turnDisplay(); //display ui elements and both boards during respective player turns
    void resolutionDisplay(string resolutionText);
    int calculatePlayerShots();
    
        
        

  private:
    Player* generatePlayers(int selection, int index); //Factory function that generates a new human or computer player, depending on menu selection
    GameType selectGameType(int selection);
    Player* mPlayers [num_Players]; //Only ever two players in a game of battleship
    int mCurrentPlayer; //the player currently taking their turn, represented by a number in order to access a specific array index
    int mInactivePlayer; //the player being targeted by enemy fire, uses a number to access the correct player's boards when updating
    GameState mGameState; //the phase the game is currently in
    GameType mGameMode; //the mode of game being played, chosen by the player on start up
};