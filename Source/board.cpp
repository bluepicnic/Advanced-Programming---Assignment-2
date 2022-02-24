#include "../Headers/headers.h"

Board::Board()
{
  //initialise Board member variables on creation
  cout << "board has been created" << endl; 
}

Board::Board(int width, int height)
{
  //set simple (primitive) variables the usual way
  mWidth = width;
  mHeight = height;

  vector <Space> tmpSpaces; //the data structure used in the board class is a vector of vectors, so we need a temporary vector to push back

  

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      tmpSpaces.push_back({i, j}); 
    } 
    spaces.push_back(tmpSpaces);
    tmpSpaces.clear(); //reset the temp vector after each line is initialised
  }
}


Board::~Board()
{
  //destroy board objects 
}


void Board::displayBoard()
{
  using std::setw; //used to set the width of an output stream 
  using std::left; //used to align an input stream to the left

	//output board edges
  /*for (int i = 0; i < 702; i++) {
    cout << i << " ";
    string output = convertToLetter(i);
    cout << output << endl;
  } */
  
  //output individual board instance, using test from earlier
  for (int i = 0; i < mHeight; i++)
  {
    //start a vert
    for (int j = 0; j < mWidth; j++)
    {
      cout << text_Colour_Black << background_Colour_Grey << setw(4) << left << spaces[i][j].outputValue << text_Colour_Default << symbol_Vertical_Line;

    }
    boardHorizLine();
    
  }
}


void Board::updateBoard()
{
  //update board for whatever reason, possibly to record a hit
}

void Board::boardHorizLine()
{
  int lineIntersection = 3; //need a fixed location to place each line cross symbol that makes up the corner of every board space

  cout << endl; //each horizontal line starts on its own line
  for (int i = 0; i < mWidth * 4; i++)
  {
    if (i == lineIntersection) { //place a corner symbol
      cout << symbol_Vertical_Horizontal_Line;
      lineIntersection += 4;
    }
    else { 
      cout << symbol_Horizontal_Line;
    } 
    
  }
  cout << endl;
}