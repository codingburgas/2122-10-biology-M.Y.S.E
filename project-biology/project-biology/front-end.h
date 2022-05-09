#pragma once
#include "pch.h"
#include "../../2122-10-biology-M.Y.S.E/project-biology/pb.bll/logic-for-objects.h"
#include "../../2122-10-biology-M.Y.S.E/project-biology/pb.bll/register.h"
#include "../../2122-10-biology-M.Y.S.E/project-biology/pb.bll/login.h"

void updateTextSize(tgui::BackendGui& gui);
void simulationScreen(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool& start, bool& backEndRun);
void mainMenu(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool &start, bool& backEndRun);
void logInScreen(tgui::BackendGui& gui, sf::RenderWindow& window, bool &start, bool& backEndRun);
int regUser(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password, tgui::EditBox::Ptr confirmPass);
void registerScreen(tgui::BackendGui& gui, sf::RenderWindow& window, bool& start, bool& backEndRun);
bool logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password);
void removeLockedOverlay(tgui::BackendGui& gui, tgui::Picture::Ptr pic);
bool displayWindow(tgui::BackendGui& gui, sf::RenderWindow& window, bool &start, bool& backEndRun);
void displayObjectButton(tgui::BackendGui& gui, tgui::Picture::Ptr picOverlay, tgui::Layout2d pos, tgui::Layout2d statsPos, std::string objectName, std::string theme, short int id);
void displayObjectStats(tgui::BackendGui& gui, tgui::Layout2d pos, std::string objectName);
bool startSimulation(bool start);
std::string giveTimeText();
void updateScreen(tgui::BackendGui& gui, bool& start);