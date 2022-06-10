#pragma once


//Game parameter constants 
inline const int num_Players = 2;
inline const int num_Boards = 2;
inline const int shipboard = 0;
inline const int targetboard = 1;

//file name used to load board and ship data 
inline const string inFile = "adaship_config.ini";


//String Literal constants for menu items
inline const string welcome_Message = "Welcome to Battleship!";
inline const string select_Game_Mode = "Please Select a game mode:";
inline const string single_Player_Game = "1. Single Player Game (vs AI Opponent)";
inline const string multiplayer_Game = "2. Multiplayer Game (PvP)";
inline const string ai_Only_Game = "3. Computer only Game (AI vs AI)";
inline const string single_Player_Salvo = "4. Single Player Salvo Game";
inline const string multiplayer_Salvo = "5. Multiplayer Salvo Game (PvP)";
inline const string ai_Only_Salvo = "6. Computer only Salvo Game (AI vs AI)";
inline const string single_Player_Mines = "7. Single Player Hidden Mines Game";
inline const string multiplayer_Mines = "8. Multiplayer Hidden Mines Game";
inline const string ai_Only_Mines = "9. Computer only Hidden Mines Game";

//boat placement menu items
inline const string manual_Boat_Selection = "1. Select a ship to manually place";
inline const string auto_Boat_Selection = "2. Select a ship to place automatically";
inline const string auto_Place_Remaining = "3. Auto-place all remaining 'available' ships";
inline const string auto_Place_All = "4. Auto-place all ships";
inline const string reset_Boats = "5. Reset all ships";
inline const string complete_Setup = "6. Confirm placements & continue...";
inline const string exit_text = "0. Quit";

//specific input prompts
inline const string placement_Prompt = "Input a position using the following format: Boat ID, Location, Orientation (1 d4 h): ";
inline const string boat_Auto_Place_Prompt = "Please select a boat to auto-place by entering an ID from the list above: ";
inline const string menu_Num_Prompt = "Enter an option from the numbers above, or 0 to quit:";


//String constants for invalid input error messages
inline const string invalid_Menu_Input = "That selection is invalid: please try again: ";
inline const string invalid_Placement_Command = "That command is invalid: please try again: ";
inline const string invalid_Ship_Selection = "That boat does not exist: please enter the ID of a valid boat: ";
inline const string invalid_Manual_Target = "That target is invalid";

//Headers for battleship game boards
inline const string ship_Board_Header = "SHIP PLACEMENT BOARD";
inline const string target_Board_Header = "TARGETING BOARD";

//Game shot resolution text
inline const string hit_Text = "\nIt's a hit! An enemy boat takes damage"; 
inline const string miss_Text = "\nIt's a miss... no damage taken.";

//characters used to find instances of the characters listed
inline const string numbers = "0123456789";
inline const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqurstuvwxyz";


//String literal constants for setting string colours using ANSI codes and RGB values
inline const string text_Colour_Default = "\u001b[0m";
inline const string text_Colour_Cyan = "\033[38;2;0;255;255m";
inline const string text_Colour_Black = "\u001b[31;1m";
inline const string text_Colour_Yellow = "\033[38;2;255;208;0m";
inline const string text_Colour_Red = "\033[38;2;255;0;0m";
inline const string text_Colour_Sky_Blue = "\033[38;2;0;199;255m";
inline const string text_Colour_Grey = "\033[38;2;87;86;83m";


//String literal constants for setting string background colours using ANSI codes
inline const string background_Colour_White = "\033[48;2;255;255;255m"; 
inline const string background_Colour_Blue = "\033[48;2;0;199;255m";

//string literal unicode symbols
inline const string symbol_Vertical_Line = "\u2502";
inline const string symbol_Vertical_Horizontal_Line = "\u253C";
inline const string symbol_Horizontal_Line = "\u2500";
inline const string symbol_Square = " \u25A0 "; //with spaces to avoid having to add later
inline const string symbol_Dot = " \u00B7 ";


//String literal constants for clearing part or all of the console screen
inline const string clear_Console_Screen = "\u001b[1H;1\u001b[0J\r"; //Clear entire console screen
inline const string clear_Console_Line = "\u001b[2K\r"; //clear current line and return cursor to start
inline const string clear_Console_Screen_Bottom = "\u001b[0J\r"; //Clear screen from cursor position to the bottom of the screen, return cursor to start of current line

//string literal constant for the movement of the cursor
inline const string console_Move_Cursor_Up = "\u001b[1A";


//String literal constants for regular expression patterns
inline const regex regex_Menu_Selection("^[0-9]+$");
inline const regex regex_Alphanumeric("^[a-zA-Z0-9 ]*$");
inline const regex regex_Setup_Menu_Selection("^[0-6]+$");
inline const regex regex_Board_Setup("^([0-9]{1,2} ?[a-zA-Z]{1,2}[0-9]{1,2} ?[vVhH])+");
inline const regex regex_Targeting("^([a-zA-Z]{1,2}[0-9]{1,2} ?)");
inline const regex regex_Salvo_Targeting("^([a-zA-Z]{1,2}[0-9]{1,2} ?)+");
inline const regex regex_Any_Key("[\\sa-zA-Z0-9 ]");
inline const regex pat_Turn_Menu("^[0-3]+$");
