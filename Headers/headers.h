#include <iostream> //For inputoutput operations
#include <vector> //to access the vector variable size data container
#include <string> //to perform string operations beyond simple C-style char* 
#include <algorithm> 
#include <fstream>
#include <sstream> //In order to perform operations on strings and
#include <iomanip> //manipulation
#include <regex> //To perform regex operations to check against input
#include <cmath> //For "pow" function to allow for more dynamic letter to number calculation
#include <random> //for functionality pertaining to random number generation (RNG); functions included are said to produce a better distribution of random numbers than standard functions such as rand() and srand()

#include <unistd.h>
#include <termios.h> 
#include <sys/stat.h>
#include <limits.h>

using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::regex;
using std::stringstream;
using std::setw; //used to set the width of an output stream 
using std::left; //used to align an input stream to the left
using std::right; //used to align an input stream to the right

#include "constants.h"
#include "udt.h"
#include "utilities.h"
#include "board.h"
#include "ship.h"
#include "player.h"
#include "aiPlayer.h"
#include "fileParser.h"
#include "game.h"
#include "humanPlayer.h"
#include "inputParser.h"
#include "ui.h"
#include "mainMenu.h"