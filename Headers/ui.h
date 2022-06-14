#pragma once

/*UI Related functions*/
void ui_clearScreen();

void ui_displayMainMenu();
void ui_boatStatusColTitles();

int ui_displayBoatPlacement(bool advance);
int ui_displayTargetSelection(string pName, int shots);

void ui_BoatPlacementPrompt();
void ui_BoatSelectionPrompt();
void ui_TargetSelectionPrompt();

void ui_GameOverText(string winner, string loser);
string ui_ContinueText();

string ui_moveCursorUp(int noLines);
void ui_saveCursorPos();
void ui_returnCursorPos();