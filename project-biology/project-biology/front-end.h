#pragma once
#include "pch.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/logic-for-objects.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/register.h"
#include "../../2122-10-biology-SSUzunov19/project-biology/pb.bll/login.h"

void updateTextSize(tgui::BackendGui& gui);
void simulationScreen(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool& start);
void mainMenu(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool &start);
void logInScreen(tgui::BackendGui& gui, sf::RenderWindow& window, bool &start);
void registerScreen(tgui::BackendGui& gui, sf::RenderWindow& window, bool& start);
void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password);
void removeLockedOverlay(tgui::BackendGui& gui, tgui::Picture::Ptr pic);
bool displayWindow(tgui::BackendGui& gui, sf::RenderWindow& window, bool &start);
bool startSimulation(bool start);