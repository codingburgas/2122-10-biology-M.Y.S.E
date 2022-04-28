#pragma once
#include "pch.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/logic-for-objects.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/register.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/login.h"

void updateTextSize(tgui::BackendGui& gui);
void simulationScreen(tgui::BackendGui& gui, tgui::Label::Ptr userName);
void mainMenu(tgui::BackendGui& gui, tgui::Label::Ptr userName);
void logInScreen(tgui::BackendGui& gui);
void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password);
bool runExample(tgui::BackendGui& gui);