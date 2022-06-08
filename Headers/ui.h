#pragma once

void ui_clearScreen();
void ui_displayMainMenu();
void ui_boatStatusColTitles();
int ui_displayBoatPlacement(bool advance);
int ui_displayTargetSelection(bool turnComplete);
void ui_BoatPlacementPrompt();
void ui_BoatSelectionPrompt();
void ui_TargetSelectionPrompt();
void ui_GameOverText(Player* winner, Player* loser);
string ui_moveCursorUp(int noLines);
void ui_saveCursorPos();
void ui_returnCursorPos();