#pragma once //include only once

class Player {
  public:
        Player();
        ~Player();
        void deployBoats();
        void deployBoats(int remainingBoats);
        void deployMines();
        virtual Coordinates selectTarget();
        //virtual bool isHuman = 0 <- Might be useful for more marks/quickly determining if an instance is human or not.
        void displayBoards();
        void fleetStatus();
  private:
        Board mTargetBoard;
        Board mShipBoard;
        vector<Ship> mFleet; 
};