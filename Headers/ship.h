#pragma once

class Ship {
    public:
    BoatStatus reportStatus();
    Coordinates reportLocation();
    
    private:
    int mSize;
    string mName;
    int mHealth;
    vector<vector<Coordinates>> MLocations;
    int mIndex;
    BoatStatus mStatus;

};