#pragma once //only include once 

class Board {
    public:
      Board();
      Board(int width, int height);
      ~Board();
      void displayBoard(); 
      void updateBoard(Coordinates coordsToUpdate, SpaceState newState); //updates board at a specific coordinate with a specific state
      int getWidth(); 
      int getHeight();
      bool isOccupied(Coordinates chkCoords); //check if a specific square on a shipboard is occupied
      void setStateColour(Coordinates colourLocation); //update a space's output colour based on its state

    private:
      void boardHorizLine(); //displays a horizontal line for each row on the board
      vector<vector<Space>> spaces; //2d array of board spaces
      int mWidth;
      int mHeight;
};