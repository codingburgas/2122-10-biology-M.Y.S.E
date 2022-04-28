#pragma once
#include "pch.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/logic-for-objects.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/register.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/login.h"

void updateTextSize(tgui::BackendGui& gui);
void simulationScreen(tgui::BackendGui& gui, tgui::Label::Ptr userName, bool& start);
void mainMenu(tgui::BackendGui& gui, tgui::Label::Ptr userName);
void logInScreen(tgui::BackendGui& gui, bool &start);
void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password);
void removeLockedOverlay(tgui::BackendGui& gui, tgui::Picture::Ptr pic);
bool runExample(tgui::BackendGui& gui, bool &start);