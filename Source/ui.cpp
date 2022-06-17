#include "../Headers/headers.h"

void ui_clearScreen() {
  
	system("clear"); 
  // this method is resource intensive, insecure, and prone to unexpected behaviour. However, it is overall more,reliable for the purpose of clearing the whole screen than using various methods of ANSI codes. This 
}

void ui_displayMainMenu() {
	ui_clearScreen();
	cout << text_Colour_Cyan << welcome_Message << endl;
	cout << select_Game_Mode << endl << text_Colour_Default;
	cout << single_Player_Game << endl;
	cout << multiplayer_Game << endl;
	cout << ai_Only_Game << endl;
	cout << single_Player_Salvo << endl;
	cout << multiplayer_Salvo << endl;
	cout << ai_Only_Salvo << endl << endl;

	ui_saveCursorPos();
	cout << menu_Num_Prompt << text_Colour_Default << endl << endl;
}

void ui_boatStatusColTitles() {
	cout << endl
		 << text_Colour_Yellow << std::setw(2) << std::right << "Id"
		 << "  " << std::setw(17) << std::left << "Name" << std::setw(8)
		 << std::left << "Size" << std::setw(8) << std::left << "Health"
		 << "Status" << text_Colour_Default;
}

int ui_displayBoatPlacement(bool advance) {
	string continueColour =
		(advance == true) ? text_Colour_Yellow : text_Colour_Grey;

	ui_saveCursorPos();
  
	// don't clear screen, we need board to be displayed
	cout << endl
		 << manual_Boat_Selection << endl // manually place ship
		 << auto_Boat_Selection << endl   // auto place ship
		 << auto_Place_Remaining
		 << endl				   // auto place boats with an "inactive" state
		 << auto_Place_All << endl // auto place all boats
		 << reset_Boats << endl	// recall all boats
		 << continueColour << complete_Setup << text_Colour_Default << endl
		 << endl // complete setup and continue
		 << exit_text << endl
		 << endl; // exit

	cout << menu_Num_Prompt << text_Colour_Default << endl << endl;

	return stoi(getLineSingleKey(
		regex_Menu_Selection,
		invalid_Menu_Input)); // take input, return as integer
}

int ui_displayTargetSelection(string pName, int shots) {
	// display menu elements for player targeting, return selection
	string turnSwapColour = text_Colour_Grey;
	string targetColour = text_Colour_Default;

	if (shots == 0) {
		turnSwapColour = text_Colour_Yellow;
		targetColour = text_Colour_Grey;
	}

	cout << text_Colour_Cyan << pName << " is firing... " << shots
		 << " shots remaining" << endl
		 << text_Colour_Default << endl;
  
  ui_saveCursorPos();
	cout << endl << targetColour << manual_fire << endl;
	cout << auto_fire << endl;
	cout << turnSwapColour << end_turn << text_Colour_Default << endl << endl;

	cout << menu_Num_Prompt << text_Colour_Default << endl << endl;

	return stoi(getLineSingleKey(pat_Turn_Menu, invalid_Menu_Input));
}

void ui_BoatPlacementPrompt() {
	ui_returnCursorPos();
	cout << clear_Console_Screen_Bottom;
	cout << placement_Prompt << endl;
	ui_saveCursorPos();
}

void ui_BoatSelectionPrompt() {
	ui_returnCursorPos();
	cout << clear_Console_Screen_Bottom;
	cout << boat_Auto_Place_Prompt << endl << endl;
}

void ui_TargetSelectionPrompt() {
	ui_returnCursorPos();
	cout << clear_Console_Screen_Bottom;
	cout << coord_Prompt << endl;
	ui_saveCursorPos();
}

void ui_GameOverText(
	string winner,
	string loser) // display winners and losers, and await input to continue
{
	cout << loser << " has no more ships left: " << winner << " wins!" << endl
		 << endl;
	cout << "GAME OVER" << endl;

	cout << return_Prompt << endl;
	getLineSingleKey(regex_Any_Key, "");
}

string ui_ContinueText() {
	cout << continue_Prompt << endl;
	return getLineSingleKey(regex_Any_Key, "");
}

string ui_moveCursorUp(int noLines) {
	using std::to_string;
	string cursor = "\u001b[" + to_string(noLines) + "A";

	return cursor;
}

void ui_saveCursorPos() // save the cursor position within the console
{
	cout << "\033[s";
	cout.flush();
}

void ui_returnCursorPos() // return the cursor position to the previously saved
						  // position
{
	cout << "\033[u";
	cout.flush();
}
