#include "../Headers/headers.h"

Ship::Ship(string name, int size, int index)
{
  mName = name;
  mSize = size;
  mHealth = mSize;
  mIndex = index;
  mStatus = BoatStatus::Inactive;
}

void Ship::vesselStatusReport() //display ship information during deployment
{
  stringstream boatSpaces; 
  
  boatSpaces << "Active @ ";
  cout << endl << 
	std::setw(2) << std::right << mIndex << "  " <<
	std::setw(17) << std::left << mName << 
	std::setw(8) << std::left << mSize <<
	std::setw(8) << std::left << mHealth;

  switch (mStatus) {
    case BoatStatus::Inactive:
      cout << "Inactive";
      break;
    case BoatStatus::Deployed:
      for (auto it: mLocations) {
        boatSpaces << convertToLetter(it.colPos+1) << it.rowPos+1 << " ";
      }
      cout << boatSpaces.str();
      break;
    case BoatStatus::Destroyed:
      cout << "Destroyed";
      break;
  }
}

BoatStatus Ship::reportStatus() 
{
  return mStatus;
}

vector <Coordinates> Ship::reportLocation()
{
  return mLocations;
}

int Ship::reportSize() 
{
  return mSize;
}

string Ship::reportDamageTaken() 
{
  mHealth--; //reduce health when hit
  if (mHealth == 0) {
    updateStatus(BoatStatus::Destroyed);
    return mName; //declare the name of the destroyed ship
  }
  return ""; 
}

void Ship::updateLocation(vector<Coordinates> shipCoords)
{
  mLocations = shipCoords;
}

void Ship::updateStatus(BoatStatus update)
{
  mStatus = update;
}