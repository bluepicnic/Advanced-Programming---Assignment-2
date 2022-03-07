#pragma once //only include once 

class Board {
    public:
          Board();
          Board(int width, int height);
          ~Board();
          void displayBoard();
          void updateBoard(Coordinates coordsToUpdate, SpaceState newState);
          int getWidth();
          int getHeight();
          bool isOccupied(Coordinates chkCoords);
          void setStateColour(Coordinates colourLocation);

    private:
          void boardHorizLine();
          vector<vector<Space>> spaces;
          int mWidth;
          int mHeight;
};