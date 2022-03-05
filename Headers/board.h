#pragma once //only include once 

class Board {
    public:
          Board();
          Board(int width, int height);
          ~Board();
          void displayBoard();
          void updateBoard(Coordinates coordsToUpdate);
          int getWidth();
          int getHeight();

    private:
          void boardHorizLine();
          vector<vector<Space>> spaces;
          int mWidth;
          int mHeight;
};