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
const string ai_Only_Game = "3. Computer only game (AI vs AI )";
const string single_Player_Salvo = "4. Single Player Salvo Game";
const string multiplayer_Salvo = "5. Multiplayer Salvo game (PvP)";
const string ai_Only_Salvo = "6. Computer only Salvo Game (AI vs AI)";
const string single_Player_Mines = "7. Single Player Hidden Mines Game";
const string multiplayer_Mines = "8. Multiplayer Hidden Mines Game";
const string ai_Only_Mines = "9. Computer only Hidden Mines Game";

//String constants for invalid input error messages
const string invalid_Menu_Input = "That selection is invalid, please try again";


//String literal constants for setting string colours using ANSI codes
const string text_Colour_Default = "\x1b[0m";
const string text_Colour_Cyan = "\u001b[36;1m";
const string text_Colour_Black = "\x1b[30m";

//String literal constants for setting string background colours using ANSI codes
const string background_Colour_Grey = "\x1b[47m"; //defined as WHITE but Ubuntu gives it a grey hue

//string literal unicode symbols
const string symbol_Vertical_Line = "\u2502";
const string symbol_Vertical_Horizontal_Line = "\u253F";
const string symbol_Horizontal_Line = "\u2501";
const string symbol_Square = " \u25A0 "; //with spaces to avoid having to add later


//String literal constants for clearing part or all of the console screen
const string clear_Console_Screen = "\x1b[2J\x1b[1;1H"; //Clear entire console screen
const string clear_Console_Line = "\x1b[2K\r"; //clear line and return cursor (\r) to start of line
const string clear_Console_Screen_Bottom = "\x1b[0J\r"; //clear to bottom and return cursor (\r) to start of line


//String literal constants for regular expression patterns
const regex regex_Menu_Selection("^[0-9]+$");
const regex regex_Alphanumeric("^[a-zA-Z0-9 ]*$");