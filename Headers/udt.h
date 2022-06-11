#pragma once

enum class BoatStatus { //use of an enum class to prevent unwanted type conversion
  Inactive, Deployed, Destroyed
}; 

enum class SpaceState {
  Inactive, Unoccupied, Occupied, Miss, Hit_Boat
};

enum class GameType {
  Invalid_Game, Regular_1P, Regular_2P, Regular_AI, Salvo_1P, Salvo_2P, Salvo_AI
};

enum class GameState { //track the state of the game throughout 
  Invalid, Setup, Firing, Resolution, Swap_Turn, End
};

struct Coordinates {
  int rowPos;  
  int colPos;
};

struct Space {
  
  Space(int col, int row) //initialise values
  {
    location.colPos = col;
    location.rowPos = row;
    outputValue = symbol_Square;
    status = SpaceState::Inactive;
    outputColour = text_Colour_Sky_Blue;
  };

  Coordinates location;
  SpaceState status;
  string outputValue;
  string outputColour;
};

struct shipCounts { 
  int totalShips;
  int shipsAfloat;
};





