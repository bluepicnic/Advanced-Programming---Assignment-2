#include <iostream> //For input/output operations
#include <vector> //to access the vector varaible size data container
#include <string> //to perform string operations beyond simple C-style char* 
#include <algorithm> 
#include <fstream>
#include <sstream> //In order to perform operations on strings and
#include <iomanip>
#include <regex> //To perform regex operations to check against input
#include <unistd.h>
#include <termios.h>
#include <sys/stat.h>
#include <cmath> //For "pow" function to allow for more dynamic letter calculation

using std::cout;
using std::cin;
using std::stoi;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::regex;
using std::stringstream;

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