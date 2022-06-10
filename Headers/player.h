#pragma once //include only once

class Player {
  public:
    Player();
    virtual ~Player();
    bool deployBoat(string command); //wrapper function for manual boat deployment
    void deployBoat(int boatID); //wrapper function for automatic boat deployment
    bool deployBoat(int boatID, Coordinates loc, string orientation); //boat deployment

    void deployBoats(); //deploys all boats automatically
    void deployBoats(BoatStatus statusToDeploy); //deploys all boats with a specific status


    virtual vector<Coordinates> selectTarget(GameType gm, int numShots) = 0;
    virtual bool isHuman() = 0; //determine if a player is human controlled

    void displayBoards(int boardNo); 
    void fleetStatus();
    string sayName(); //returns the player's set name

    void recallBoat(int boatNo); //recalls a specific boat from board placement
    void recallBoats(); //recalls all boats

    int relayFleetSize();
    Coordinates autoTarget(); 
    bool isSpaceOccupied(Coordinates target); //check if a space is occupied by a boat
    bool previouslyTargeted(Coordinates target); //check if a space has been previously targeted on the target bpard
    shipCounts reportBoatCounts(); //total number of boats and boats currently active
    string acknowledgeShot(int board, Coordinates shotTarget, SpaceState acknowledgement); //print text related to player turn actions

  private:
    vector<Ship> mFleet; 

  protected:
    Board mPlayerBoards [2]; //target and ship boards
    string mPlayerName; //used for ui and player identification
};