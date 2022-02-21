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
    for (int j = 0; j < width; i++)
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
  //output individual board instance, using test from earlier
}


void Board::updateBoard()
{
  //update board for whatever reason 
}