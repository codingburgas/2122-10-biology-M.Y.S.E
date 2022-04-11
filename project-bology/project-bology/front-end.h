#pragma once
#include "pch.h"

void showScreen2(tgui::BackendGui& gui);
void loadWidgets(tgui::BackendGui& gui);
void logInScreen(tgui::BackendGui& gui);
void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password);
bool runExample(tgui::BackendGui& gui);