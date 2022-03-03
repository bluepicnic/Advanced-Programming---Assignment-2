#include "../Headers/headers.h"

Ship::Ship(string name, int size, int index)
{
  mName = name;
  mSize = size;
  mHealth = mSize;
  mIndex = index;
}

void Ship::reportStatus()
{
  cout << endl << 
	std::setw(2) << std::right << mIndex << "  " <<
	std::setw(17) << std::left << mName << 
	std::setw(8) << std::left << mSize <<
	std::setw(8) << std::left << mHealth <<
	"Status";
}


Coordinates Ship::reportLocation()
{
  Coordinates location;
  return location;
}