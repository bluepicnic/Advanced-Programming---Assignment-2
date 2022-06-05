#pragma once

void ui_clearScreen();
void ui_displayMainMenu();
void ui_boatStatusColTitles();
int ui_displayBoatPlacement();
int ui_displayTargetSelection();
void ui_BoatPlacementPrompt();
void ui_BoatSelectionPrompt();
void ui_TargetSelectionPrompt();
string ui_moveCursorUp(int noLines);
void ui_saveCursorPos();
void ui_returnCursorPos();