#pragma once

enum class BoatStatus { //use of an enum class to prevent unwanted type conversion
  Inactive, Deployed, Recalled, Destroyed
}; 

enum class SpaceStatus {
  Inactive, Unoccupied, Occupied, Miss, Hit_Boat, Hit_Mine, Hit_Mine_And_Boat 
};

enum class GameType {
  Invalid_Game, Regular_1P, Regular_2P, Regular_AI, Salvo_1P, Salvo_2P, Salvo_AI, Mines_1P, Mines_2P, Mines_AI
};

enum class Direction {
  North, East, South, West
};

enum class GameState {
  Invalid, Setup, Firing, Resolution, Swap_Turn, End
};

struct Coordinates {
  int cosPos;
  int rowPos;
};

struct Space {
  
  Space(int col, int row)
  {
    location.cosPos = col;
    location.rowPos = row;
    outputValue = symbol_Square;
    status = SpaceStatus::Unoccupied;
  };

  Coordinates location;
  SpaceStatus status;
  string outputValue;

  

};





