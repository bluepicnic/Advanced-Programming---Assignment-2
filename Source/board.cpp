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
  using std::right;
  using std::internal;

	//output column labels
  
  cout << endl << setw(2) << right << "" << " " << setw(1) << right << std::setfill(' ') << "" << " " << text_Colour_Default;
  
  for (int i = 0; i <= mWidth; i++) {
    string output = convertToLetter(i);
    cout << output << setw(4) << left;
  } 
  cout << endl;
  
  for(int i = 0; i < mWidth * 4; i++) {
    cout << symbol_Horizontal_Line;
  }

  //output individual board instance, using test from earlier
  for (int i = 0; i < mHeight; i++) {
    //start a vertical line
    cout << endl << setw(2) << right << (i + 1) << " " << setw(2) << right << symbol_Vertical_Line << text_Colour_Default;
    
    for (int j = 0; j < mWidth; j++) {
      cout << spaces[i][j].outputColour << background_Colour_Blue << setw(4) << left << spaces[i][j].outputValue << text_Colour_Default << symbol_Vertical_Line;

    }
    boardHorizLine();
    
  }

  cout << endl << endl;
}


void Board::updateBoard(Coordinates coordsToUpdate, SpaceState newState)
{
  spaces[coordsToUpdate.rowPos][coordsToUpdate.colPos].status = newState;
  setStateColour(coordsToUpdate);
}

void Board::boardHorizLine()
{
  using std::setw;
  using std::right;
  
  int lineIntersection = 0; //need a fixed location to place each line cross symbol that makes up the corner of every board space

  //each horizontal line starts on its own line
  cout << endl << setw(2) << right << "   " << setw(4) << right << text_Colour_Default;
  for (int i = 0; i < (mWidth * 4) + 1; i++)
  {
    if (i == lineIntersection) { //place a corner symbol
      cout << symbol_Vertical_Horizontal_Line;
      lineIntersection += 4;
    }
    else { 
      cout << symbol_Horizontal_Line;
    } 
    
  }
}



int Board::getWidth() 
{
  return mWidth;
}

int Board::getHeight()
{
  return mHeight;
}


bool Board::isOccupied(Coordinates chkCoords) 
{
  return (spaces[chkCoords.rowPos][chkCoords.colPos].status == SpaceState::Occupied);
}

void Board::setStateColour(Coordinates colourLocation) 
{
  string stateColour = "";
  
  switch (spaces[colourLocation.rowPos][colourLocation.colPos].status) {
    case SpaceState::Inactive:
    
    case SpaceState::Unoccupied: 
    stateColour = text_Colour_Black;
    break;
    
    case SpaceState::Occupied:
    stateColour = text_Colour_Yellow;
    break;
    
    case SpaceState::Miss: 
    
    case SpaceState::Hit_Boat: 
    stateColour = text_Colour_Red;
    break;
    
    //case SpaceState::Hit_Mine: 
    //case SpaceState::Hit_Mine_And_Boat:
    default:
    stateColour = text_Colour_Default;
    break;
  }

  spaces[colourLocation.rowPos][colourLocation.colPos].outputColour = stateColour;
}