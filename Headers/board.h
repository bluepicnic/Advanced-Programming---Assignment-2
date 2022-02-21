#pragma once //only include once 

class Board {
    public:
          Board();
          Board(int width, int height);
          ~Board();
          void displayBoard();
          void updateBoard();

    private:
          vector<vector<Space>> spaces;
          int mWidth;
          int mHeight;
};