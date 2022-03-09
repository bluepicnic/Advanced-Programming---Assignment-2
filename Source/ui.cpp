#include "../Headers/headers.h"

void ui_clearScreen()
{
  cout << clear_Console_Screen;
  cout.flush();
}

void ui_displayMainMenu() 
{
    ui_clearScreen();
    cout << text_Colour_Cyan << welcome_Message << endl; 
    cout << select_Game_Mode << endl << text_Colour_Default;
    cout << single_Player_Game << endl;
    cout << multiplayer_Game << endl;
    cout << ai_Only_Game << endl;
    cout << single_Player_Salvo << endl;
    cout << multiplayer_Salvo << endl;
    cout << ai_Only_Salvo << endl;
    cout << single_Player_Mines << endl;
    cout << multiplayer_Mines << endl;
    cout << ai_Only_Mines << endl;
    cout << endl << endl;
}

void ui_boatStatusColTitles() 
{
  cout << endl << text_Colour_Yellow << 
	std::setw(2) << std::right << "Id" << "  " <<
	std::setw(17) << std::left << "Name" << 
	std::setw(8) << std::left << "Size" <<
	std::setw(8) << std::left << "Health" <<
	"Status" << text_Colour_Default;
}

int ui_displayBoatPlacement() 
{
  //don't clear screen, we need board to be displayed 
  cout << endl << manual_Boat_Selection << endl //manually place ship
  << auto_Boat_Selection << endl //place ship
  << auto_Place_Remaining << endl
  << auto_Place_All << endl
  << reset_Boats << endl
  << complete_Setup << endl << endl
  << exit_text << endl << endl << endl;

  return stoi(getLineSingleKey(regex_Menu_Selection, invalid_Menu_Input));
}

void ui_BoatPlacementPrompt() 
{
  ui_returnCursorPos();
  cout << clear_Console_Screen_Bottom;
  cout << placement_Prompt << endl;
  ui_saveCursorPos();
}

void ui_BoatSelectionPrompt() 
{
  ui_returnCursorPos();
  cout << clear_Console_Screen_Bottom;
  cout << boat_Auto_Place_Prompt << endl;
  ui_saveCursorPos();
}

string ui_moveCursorUp(int noLines)
{
  using std::to_string;
  string cursor = "\u001b[" + to_string(noLines) + "A";

  return cursor;
}

void ui_saveCursorPos() 
{
  cout << "\033[s";
  cout.flush();
}

void ui_returnCursorPos()
{
  cout << "\033[u";
  cout.flush();
}


