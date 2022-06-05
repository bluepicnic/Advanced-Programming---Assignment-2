#include "../Headers/headers.h"

Board::Board()
{
  //initialise Board member variables on creation
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
  //indent output to align column labels with space output
  cout << endl << endl << setw(5) << right << " " << text_Colour_Default;
  //output column labels  
  for (int i = 0; i <= mWidth; i++) {
    string output = convertToLetter(i);
    cout << output << setw(4) << left;
  } 

  //align top line of the board with the width of the board itself
  cout << endl << setw(3) << right << " ";
  //output the top of the board
  for(int i = 0; i < (mWidth * 4) + 1; i++) {
    cout << symbol_Horizontal_Line;
  }

  //output the board itself
  for (int i = 0; i < mHeight; i++) {
    //output row number and start a vertical line on the left edge of the board
    cout << endl << setw(2) << right << (i + 1) << " " << setw(2) << right << symbol_Vertical_Line << text_Colour_Default;
    
    for (int j = 0; j < mWidth; j++) {
      cout << spaces[i][j].outputColour << background_Colour_Blue << setw(4) << left << spaces[i][j].outputValue << text_Colour_Default << symbol_Vertical_Line;

    }
    boardHorizLine(); //output lines to separate each space, with a cross symbol being used where lines intersect
    
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
  int lineIntersection = 0; //need a fixed location to place each line cross symbol that makes up the corner of every board space

  //each horizontal line starts on a new line
  cout << endl << setw(3) << right << "   " << text_Colour_Default;
  for (int i = 0; i < (mWidth * 4) + 1; i++) {
    if (i == lineIntersection) { //place a corner symbol where lines intersect
      cout << symbol_Vertical_Horizontal_Line;
      lineIntersection += 4;
    } else { 
      cout << symbol_Horizontal_Line; //otherwise just output a standard horizontal line 
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
  return (spaces[chkCoords.rowPos][chkCoords.colPos].status == SpaceState::Occupied); //check if a space is occupied 
}

void Board::setStateColour(Coordinates colourLocation) 
{
  string stateColour = "";
  
  switch (spaces[colourLocation.rowPos][colourLocation.colPos].status) {
    case SpaceState::Inactive: {
      stateColour = text_Colour_Sky_Blue;
      break;
    }
    
    case SpaceState::Unoccupied: {
      stateColour = text_Colour_Black;
      break;
    }
    
    case SpaceState::Occupied: {
      stateColour = text_Colour_Yellow;
      break;
    }
    
    case SpaceState::Miss: {
      stateColour = "\033[38;2;255;255;255m";
      break;
    }
    
    case SpaceState::Hit_Boat: {
      stateColour = text_Colour_Red;
      break;
    }
    
    //case SpaceState::Hit_Mine: 
    //case SpaceState::Hit_Mine_And_Boat:
    default: {
      stateColour = text_Colour_Default;
      break;
    }
    
  }
  //set a space's symbol colour depending on its state
  spaces[colourLocation.rowPos][colourLocation.colPos].outputColour = stateColour;
}

SpaceState Board::getSpaceStatus (Coordinates targetSpace) 
{
  return spaces[targetSpace.rowPos][targetSpace.colPos].status;
}