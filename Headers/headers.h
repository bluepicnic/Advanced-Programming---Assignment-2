/*External dependencies*/
#include <iostream>
#include <vector> //to access the vector variable size data container
#include <string> //to perform string operations beyond simple C-style char* 
#include <algorithm> 
#include <fstream>
#include <sstream> //In order to perform operations on strings and
#include <iomanip> //manipulation
#include <regex> //To perform regex operations to check against input
#include <cmath> //For "pow" function to allow for more dynamic letter to number calculation
#include <random> //for functionality pertaining to random number generation (RNG); functions included are said to produce a better distribution of random numbers than standard functions such as rand() and srand()
#include <climits> //contains constant values with the maximum possible values for primitive types
#include <cassert> //used for assertions, to prevent the program from running in the event of a condition that should never occur.
#include <set>

#include <unistd.h> //for getting input from a single key
#include <termios.h> //command line control 
#include <sys/stat.h> //used for obtaining attributes of files


/*STD namespace functions and types*/
//individually included to preserve resources
using std::cout; //output to the console
using std::cin; //take input from the console
using std::stoi; //convert a string to an integer
using std::endl; //denote the end of a line
using std::string; //enables the use of the string type
using std::vector; //enables the use of the vector class
using std::ifstream; //operates on files
using std::regex; //enables the use of the regex type, for regular expressions
using std::stringstream; //used to operate on strings
using std::setw; //used to set the width of an output stream 
using std::left; //used to align an input stream to the left
using std::right; //used to align an input stream to the right
using std::set;


/*Project header files*/
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