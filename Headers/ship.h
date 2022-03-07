#pragma once

class Ship {
    public:
    Ship(string name, int size, int index);
    void reportStatus();
    vector<Coordinates> reportLocation();
    int reportSize();
    void updateLocation( vector<Coordinates> shipCoords);
    
    private:
    int mSize;
    string mName;
    int mHealth;
    vector<Coordinates> mLocations;
    int mIndex;
    BoatStatus mStatus;

};