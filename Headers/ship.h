#pragma once

class Ship {
    public:
    Ship(string name, int size, int index);
    void reportStatus();
    Coordinates reportLocation();
    int reportSize();
    
    private:
    int mSize;
    string mName;
    int mHealth;
    vector<vector<Coordinates>> MLocations;
    int mIndex;
    BoatStatus mStatus;

};