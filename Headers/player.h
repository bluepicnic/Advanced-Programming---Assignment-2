#pragma once //include only once

class Player {
  public:
        Player();
        ~Player();
        bool deployBoat(string command);
        void deployBoat(int boatID);
        void deployBoats();
        void deployBoats(BoatStatus statusToDeploy)
        void deployMines();
        //void setupBoards(); <- set width and height 
        virtual Coordinates selectTarget();
        //virtual bool isHuman = 0 <- Might be useful for more marks/quickly determining if an instance is human or not. If typeof player doesn't work 
        void displayBoards();
        void fleetStatus();
        string sayName();
        void recallBoat(int boatNo);
  private:
        Board mPlayerBoards [2];
        vector<Ship> mFleet; 
  protected:
        string mPlayerName;
};