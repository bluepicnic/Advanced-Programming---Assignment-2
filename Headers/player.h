#pragma once //include only once

class Player {
  public:
        Player();
        ~Player();
        void deployBoats();
        void deployBoats(int remainingBoats);
        void deployMines();
        virtual Coordinates selectTarget();
        void displayBoards();
        void fleetStatus();
  private:
        Board* mTargetBoard;
        Board* mShipBoard;
        vector<Ship*> mFleet; 
};