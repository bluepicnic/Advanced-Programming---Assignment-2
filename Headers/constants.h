#pragma once


//Game parameter constants 
const int num_Players = 2;
const int num_Boards = 2;

//string literal file name constants
const string inFile = "adaship_config.ini";


//String Literal constants for menu items
const string welcome_Message = "Welcome to Battleship!";
const string select_Game_Mode = "Please Select a game mode:";
const string single_Player_Game = "1. Single Player Game (vs AI Opponent)";
const string multiplayer_Game = "2. Multiplayer Game (PvP)";
const string ai_Only_Game = "3. Computer only Game (AI vs AI)";
const string single_Player_Salvo = "4. Single Player Salvo Game";
const string multiplayer_Salvo = "5. Multiplayer Salvo Game (PvP)";
const string ai_Only_Salvo = "6. Computer only Salvo Game (AI vs AI)";
const string single_Player_Mines = "7. Single Player Hidden Mines Game";
const string multiplayer_Mines = "8. Multiplayer Hidden Mines Game";
const string ai_Only_Mines = "9. Computer only Hidden Mines Game";

//boat placement menu items
const string manual_Boat_Selection = "1. Select a ship to manually place";
const string auto_Boat_Selection = "2. Select a ship to place automatically";
const string auto_Place_Remaining = "3. Auto-place all remaining 'available' ships";
const string auto_Place_All = "4. Auto-place all ships";
const string reset_Boats = "5. Reset all ships";
const string complete_Setup = "6. Confirm placements & continue...";
const string exit_text = "0. Quit";

//specific input prompts
const string placement_Prompt = "Input a position using the following format: Boat ID, Location, Orientation (1 d4 h): ";
const string boat_Auto_Place_Prompt = "Please select a boat to auto-place by entering an ID from the list above: ";


//String constants for invalid input error messages
const string invalid_Menu_Input = "That selection is invalid: please try again: ";
const string invalid_Placement_Command = "That command is invalid: please try again: ";
const string invalid_Ship_Selection = "That boat does not exist: please enter the ID of a valid boat: ";
const string invalid_Manual_Target = "That target is invalid"

//Headers for boards
const string ship_Board_Header = "SHIP PLACEMENT BOARD";
const string target_Board_Header = "TARGETING BOARD";


//String literal constants for setting string colours using ANSI codes and RGB values
const string text_Colour_Default = "\u001b[0m";
const string text_Colour_Cyan = "\033[38;2;0;255;255m";
const string text_Colour_Black = "\u001b[31;1m";
const string text_Colour_Yellow = "\033[38;2;255;208;0m";
const string text_Colour_Red = "\033[38;2;255;0;0m";
const string text_Colour_Sky_Blue = "\033[38;2;0;199;255m";

//String literal constants for setting string background colours using ANSI codes
const string background_Colour_White = "\033[48;2;255;255;255m"; 
const string background_Colour_Blue = "\033[48;2;0;199;255m";

//string literal unicode symbols
const string symbol_Vertical_Line = "\u2502";
const string symbol_Vertical_Horizontal_Line = "\u253C";
const string symbol_Horizontal_Line = "\u2500";
const string symbol_Square = " \u25A0 "; //with spaces to avoid having to add later
const string symbol_Dot = " \u00B7 ";


//String literal constants for clearing part or all of the console screen
const string clear_Console_Screen = "\u001b[1H;1\u001b[0J\r"; //Clear entire console screen
const string clear_Console_Line = "\u001b[2K\r"; //clear current line and return cursor to start
const string clear_Console_Screen_Bottom = "\u001b[0J\r"; //Clear screen from cursor position to the bottom of the screen, return cursor to start of current line

//string literal constant for the movement of 
const string console_Move_Cursor_Up = "\u001b[1A";


//String literal constants for regular expression patterns
const regex regex_Menu_Selection("^[0-9]+$");
const regex regex_Alphanumeric("^[a-zA-Z0-9 ]*$");
const regex regex_Setup_Menu_Selection("^[0-6]+$");
const regex regex_Board_Setup("^([0-9]{1,2} ?[a-zA-Z]{1,2}[0-9]{1,2} ?[vVhH])+");
const regex regex_Targeting("^([a-zA-Z]{1,2}[0-9]{1,2} ?)+");
const regex regex_Any_Key("./g");
const regex pat_Turn_Menu("^[0-2]+$");
