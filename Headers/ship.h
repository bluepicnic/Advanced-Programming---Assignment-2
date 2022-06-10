#pragma once

class Ship {
    public:
      Ship(string name, int size, int index);

      void vesselStatusReport(); //
      BoatStatus reportStatus(); 

      vector<Coordinates>reportLocation();
      int reportSize();
      string reportDamageTaken(); //update health of ship, and the status if boat is destroyed

      void updateLocation(vector<Coordinates> shipCoords);
      void updateStatus(BoatStatus update);
    
    private:
      int mSize;
      string mName;
      int mHealth;
      vector<Coordinates> mLocations; //list of coordinates that the ship occupies
      int mIndex; //ID of ship
      BoatStatus mStatus;

};