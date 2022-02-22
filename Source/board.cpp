#include "../Headers/headers.h"

Board::Board()
{
  //initialise Board member variables on creation
  cout << "board has been created" << endl; 
}

Board::Board(int width, int height)
{
  mWidth = width;
  mHeight = height;

  vector <Space> tmpSpaces;

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      tmpSpaces.push_back({i, j});
    } 
    spaces.push_back(tmpSpaces);
    tmpSpaces.clear();
  }
}


Board::~Board()
{
  //destroy board objects 
}


void Board::displayBoard()
{
  using std::setw;
  using std::left;

  //output individual board instance, using test from earlier
  for (int i = 0; i < mHeight; i++)
  {
    for (int j = 0; j < mWidth; j++)
    {
      cout << "\x1b[30m" << "\x1b[47m" << setw(3) << left << spaces[i][j].outputValue << "\x1b[100m" << "\u2551";

    }
    boardHorizLine();
    
  }
}


void Board::updateBoard()
{
  //update board for whatever reason 
}

void Board::boardHorizLine()
{
  int lineIntersection = 3;

  cout << endl;
  for (int i = 0; i < mWidth * 4; i++)
  {
    if (i == lineIntersection) {
      cout << "\u256C";
      lineIntersection += 4;
    }
    else {
      cout << "\u2550";
    } 
    
  }
  cout << endl;
}