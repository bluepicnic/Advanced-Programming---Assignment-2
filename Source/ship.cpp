#include "../Headers/headers.h"

Ship::Ship(string name, int size, int index)
{
  mName = name;
  mSize = size;
  mHealth = mSize;
  mIndex = index;
}

BoatStatus Ship::reportStatus()
{
  return mStatus;
}


Coordinates Ship::reportLocation()
{
  Coordinates location;
  return location;
}