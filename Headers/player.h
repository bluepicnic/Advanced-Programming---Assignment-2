#pragma once //include only once

class Player {
  public:
    Player();
    ~Player();
    bool deployBoat(string command); //wrapper function for manual boat deployment
    void deployBoat(int boatID); //wrapper function for automatic boat deployment
    bool deployBoat(int boatID, Coordinates loc, string orientation); //boat deployment
    void deployBoats(); //deploys all boats automatically
    void deployBoats(BoatStatus statusToDeploy); //deploys all boats with a specific status
    //void setupBoards(); <- set width and height 
    virtual Coordinates selectTarget(); 
    virtual bool isHuman() = 0; //pure virtual function use in AIPlayer and Human player classes to determine if the player is human controlled 
    void displayBoards(int boardNo); 
    void fleetStatus();
    string sayName(); //returns the player's set name
    void recallBoat(int boatNo); //recalls a specific boat from board placement
    void recallBoats(); //recalls all boats 
    int relayFleetSize();
    Coordinates autoTarget();

  private:
    Board mPlayerBoards [2]; //target and ship boards
    vector<Ship> mFleet; 

  protected:
    string mPlayerName; //used for ui and player identification
};