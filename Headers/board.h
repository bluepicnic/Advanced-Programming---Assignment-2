#pragma once //only include once 

class Board {
    public:
          Board();
          ~Board();
          void displayBoard();
          void updateBoard();

    private:
          vector<vector<Space*>> spaces;
          int mWidth;
          int mHeight;
};