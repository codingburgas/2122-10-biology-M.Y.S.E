#pragma once
#include "pch.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/register.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/login.h"

void updateTextSize(tgui::BackendGui& gui);
void showScreen2(tgui::BackendGui& gui);
void mainMenu(tgui::BackendGui& gui);
void logInScreen(tgui::BackendGui& gui);
void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password);
bool runExample(tgui::BackendGui& gui);