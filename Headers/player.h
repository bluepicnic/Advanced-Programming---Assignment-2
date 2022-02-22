#pragma once //include only once

class Player {
  public:
        Player();
        ~Player();
        void deployBoats();
        void deployBoats(int remainingBoats);
        void deployMines();
        //void setupBoards(); <- set width and height 
        virtual Coordinates selectTarget();
        //virtual bool isHuman = 0 <- Might be useful for more marks/quickly determining if an instance is human or not.
        void displayBoards();
        void fleetStatus();
        string sayName();
  private:
        Board mPlayerBoards [2];
        vector<Ship> mFleet; 
  protected:
        string mPlayerName;
};