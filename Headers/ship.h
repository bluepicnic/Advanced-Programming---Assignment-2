#pragma once

class Ship {
    public:
      Ship(string name, int size, int index);
      void vesselStatusReport();
      BoatStatus reportStatus();
      vector<Coordinates>reportLocation();
      int reportSize();
      void updateLocation(vector<Coordinates> shipCoords);
      void updateStatus(BoatStatus update);
    
    private:
      int mSize;
      string mName;
      int mHealth;
      vector<Coordinates> mLocations;
      int mIndex;
      BoatStatus mStatus;

};