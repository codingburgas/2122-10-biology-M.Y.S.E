#include "front-end.h"
#include "front-to-back-end.h"

void updateTextSize(tgui::BackendGui& gui)
{
    const float windowHeight = gui.getView().getRect().height;
    gui.setTextSize(static_cast<unsigned int>(0.04f * windowHeight));
}

void removeLockedOverlay(tgui::BackendGui& gui, tgui::Picture::Ptr pic)
{
    gui.remove(pic);
}

bool startSimulation(bool start)
{
    return !start;
}

std::string giveTimeText()
{
    unsigned short int days = 1;
    std::string month = "1";
    std::string season = "1";
    std::string textTime;
    int i = 0, temp = 1;
    std::fstream fileTime;

    fileTime.open("../pb.dal/files/time.txt");

    while (getline(fileTime, textTime, '|')) {
        switch (i) {
        case 0: days = stoi(textTime); break;
        case 1: month = textTime; break;
        case 2: season = textTime; break;
        case 3: temp = stoi(textTime); break;
        }
        ++i;
    }

    fileTime.close();

    std::string timeText = std::to_string(days) + " " + month + " " + season + " " + std::to_string(temp);

    return timeText;
}

void updateScreen(tgui::BackendGui& gui, bool& start)
{
    gui.remove(gui.get("LabelTime"));

    if (gui.get("ButtonStart"))
    {
        tgui::Theme menuTheme{ "../src/theme-menu.txt" };

        auto label = tgui::Label::create();
        label->setPosition({ "10.62%", "79.89%" });
        label->setText(giveTimeText());
        label->setRenderer(menuTheme.getRenderer("LabelTime"));
        label->setTextSize(16);
        gui.add(label, "LabelTime");
    }

    if (gui.get("ButtonPlay"))
    {
        gui.remove(gui.get("LabelTime"));
    }
}

void displayObjectButton(tgui::BackendGui& gui, tgui::Picture::Ptr picOverlay, tgui::Layout2d pos, tgui::Layout2d statsPos, std::string objectName, std::string theme, short int id)
{
    tgui::Theme objectsTheme{ "../src/objects/objects.txt" };

    auto buttonObject = tgui::Button::create();
    buttonObject->setSize({ "4.68%", "9.09%" });
    buttonObject->setPosition(pos);
    buttonObject->setRenderer(objectsTheme.getRenderer(theme));
    buttonObject->onPress([&gui, picOverlay ] { removeLockedOverlay(gui, picOverlay); });
    buttonObject->onPress([&gui, statsPos, objectName ] { displayObjectStats(gui, statsPos, objectName); });
    buttonObject->onPress([id] {
        std::ofstream choiceFileS("../pb.dal/files/choice.txt", std::ios::trunc);
        choiceFileS << id;
        choiceFileS.close();
        });

    gui.add(buttonObject);
}

void displayObjectStats(tgui::BackendGui& gui, tgui::Layout2d pos, std::string objectName)
{
    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    auto labelPop = tgui::Label::create();
    auto labelMale = tgui::Label::create();
    auto labelFemale = tgui::Label::create();
    auto labelDead = tgui::Label::create();
    auto labelTemp = tgui::Label::create();
    auto labelHgr = tgui::Label::create();

    labelPop->setPosition("48.19%", "31.20");
    labelMale->setPosition("48.19%", "61.20");
    labelFemale->setPosition("48.19%", "91.20");
    labelDead->setPosition("79.27%", "31.20");
    labelTemp->setPosition("79.27%", "61.20");
    labelHgr->setPosition("79.27%", "91.20");

    labelPop->setText("asd");
    labelMale->setText("asd1");
    labelFemale->setText("asd2");
    labelDead->setText("asd");
    labelTemp->setText("asd1");
    labelHgr->setText("asd2");

    auto panel = tgui::Panel::create();
    panel->setSize({ "21.61%", "12.62%" });
    panel->setPosition(pos);
    panel->setRenderer(menuTheme.getRenderer("PanelStats"));

    panel->add(labelPop);
    panel->add(labelMale);
    panel->add(labelFemale);
    panel->add(labelDead);
    panel->add(labelTemp);
    panel->add(labelHgr);

    labelPop->getRenderer()->setTextSize(23);
    labelMale->getRenderer()->setTextSize(23);
    labelFemale->getRenderer()->setTextSize(23);
    labelDead->getRenderer()->setTextSize(23);
    labelTemp->getRenderer()->setTextSize(23);
    labelHgr->getRenderer()->setTextSize(23);

    gui.add(panel, objectName);
}

tgui::Picture::Ptr createLockedOverlay(tgui::BackendGui& gui, tgui::Layout2d pos)
{
    auto lockedOverlay = tgui::Picture::create("../src/objects/locked.png");
    lockedOverlay->setSize({ "21.61%", "12.62%" });
    lockedOverlay->setPosition(pos);
    return lockedOverlay;
}

bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void simulationScreen(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool& start, bool& backEndRun)
{

    unsigned short int days = 1;
    std::string month = "January";
    std::string season = "Winter";
    std::string textTime;
    int i = 0, temp = 1;
    std::fstream timeFile("../pb.dal/files/time.txt");

    if (days == 1 && month == "January")
    {
        timeFile << days << "|";
        timeFile << month << "|";
        timeFile << season << "|";
        timeFile << temp;

        timeFile.close();
    }

    timeFile.open("../pb.dal/files/time.txt");

    while (getline(timeFile, textTime, '|')) {
        switch (i) {
        case 0: days = stoi(textTime); break;
        case 1: month = textTime; break;
        case 2: season = textTime; break;
        case 3: temp = stoi(textTime); break;
        }
        ++i;
    }

    timeFile.close();

    gui.removeAllWidgets();

    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    auto symulationBackground = tgui::Picture::create("../src/sym-ui.png");
    symulationBackground->setSize({ "100%", "100%" });
    gui.add(symulationBackground);

    // Sistem manipulation
    auto buttonStart = tgui::Button::create("");
    buttonStart->setSize({ "8.85%", "17.17%" });
    buttonStart->setPosition({ "1.25%", "80.10%" });
    buttonStart->setRenderer(menuTheme.getRenderer("ButtonStart"));
    buttonStart->onPress([&start] { start = startSimulation(start); });

    gui.add(buttonStart, "ButtonStart");

    auto buttonExit = tgui::Button::copy(buttonStart);
    buttonExit->setPosition({ "78.95%", "80.10%" });
    buttonExit->setRenderer(menuTheme.getRenderer("ButtonExit"));
    buttonExit->onPress([&gui, &window, userName, &start, &backEndRun] { mainMenu(gui, window, userName, start, backEndRun); });
    gui.add(buttonExit);

    // Locked items

    // First column
    auto grassLocked = createLockedOverlay(gui, { "0.52%", "10.60%" });
    gui.add(grassLocked);

    auto blueberryLocked = createLockedOverlay(gui, { "0.52%", "24.24%" });
    gui.add(blueberryLocked);

    auto flowerLocked = createLockedOverlay(gui, { "0.52%", "37.87%" });
    gui.add(flowerLocked);

    // Second column
    auto grasshopperLocked = createLockedOverlay(gui, { "22.65%", "10.60%" });
    gui.add(grasshopperLocked);

    auto butterflyLocked = createLockedOverlay(gui, { "22.65%", "24.24%" });
    gui.add(butterflyLocked);

    auto rabbitLocked = createLockedOverlay(gui, { "22.65%", "37.87%" });
    gui.add(rabbitLocked);

    auto beeLocked = createLockedOverlay(gui, { "22.65%", "51.51%" });
    gui.add(beeLocked);

    // Third column
    auto mouseLocked = createLockedOverlay(gui, { "44.79%", "10.60%" });
    gui.add(mouseLocked);

    auto lizardLocked = createLockedOverlay(gui, { "44.79%", "24.24%" });
    gui.add(lizardLocked);

    auto owlLocked = createLockedOverlay(gui, { "44.79%", "37.87%" });
    gui.add(owlLocked);

    auto foxLocked = createLockedOverlay(gui, { "44.79%", "51.51%" });
    gui.add(foxLocked);

    auto snakeLocked = createLockedOverlay(gui, { "44.79%", "65.15%" });
    gui.add(snakeLocked);

    // Fourth column
    auto bearLocked = createLockedOverlay(gui, { "66.92%", "10.60%" });
    gui.add(bearLocked);
    // Object buttons

    // First column
    displayObjectButton(gui, grassLocked, { "89.37%", "4.74%" }, { "0.52%", "10.60%" }, "Grass", "ButtonObjGrass", 0);
    displayObjectButton(gui, blueberryLocked, { "94.47%", "4.74%" }, { "0.52%", "24.24%" }, "Blueberry", "ButtonObjBlueberry", 1);
    displayObjectButton(gui, flowerLocked, { "89.37%", "14.64%" }, { "0.52%", "37.87%" }, "Flower", "ButtonObjFlower", 2);

    // Second column
    displayObjectButton(gui, grasshopperLocked, { "94.47%", "14.64%" }, { "22.65%", "10.60%" }, "Grasshopper", "ButtonObjGrasshopper", 3);
    displayObjectButton(gui, butterflyLocked, { "89.37%", "24.54%" }, { "22.65%", "24.24%" }, "Butterfly", "ButtonObjButterfly", 4);
    displayObjectButton(gui, rabbitLocked, { "94.47%", "24.54%" }, { "22.65%", "37.87%" }, "Rabbit", "ButtonObjRabbit", 5);
    displayObjectButton(gui, beeLocked, { "89.37%", "34.44%" }, { "22.65%", "51.51%" }, "Bee", "ButtonObjBee", 6);

    // Third column
    displayObjectButton(gui, mouseLocked, { "94.47%", "34.44%" }, { "44.79%", "10.60%" }, "Mouse", "ButtonObjMouse", 7);
    displayObjectButton(gui, lizardLocked, { "89.37%", "44.34%" }, { "44.79%", "24.24%" }, "Lizard", "ButtonObjLizard", 8);
    displayObjectButton(gui, owlLocked, { "94.47%", "44.34%" }, { "44.79%", "37.87%" }, "Owl", "ButtonObjOwl", 9);
    displayObjectButton(gui, foxLocked, { "89.37%", "54.24%" }, { "44.79%", "51.51%" }, "Fox", "ButtonObjFox", 10);
    displayObjectButton(gui, snakeLocked, { "94.47%", "54.24%" }, { "44.79%", "65.15%" }, "Snake", "ButtonObjSnake", 11);

    // Fourth column
    displayObjectButton(gui, bearLocked, { "89.37%", "64.14%" }, { "66.92%", "10.60%" }, "Bear", "ButtonObjBear", 12);
}

void aboutUsScreen(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool& start, bool& backEndRun)
{
    gui.removeAllWidgets();

    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    auto aboutUsBackground = tgui::Picture::create("../src/about-us.png");
    aboutUsBackground->setSize({ "100%", "100%" });
    gui.add(aboutUsBackground);

    auto buttonBack = tgui::Button::create();
    buttonBack->setSize({ "18.22%", "6.06%" });
    buttonBack->setPosition({ "77.86%", "61.71%" });
    buttonBack->setRenderer(menuTheme.getRenderer("ButtonBack-AboutUs"));
    buttonBack->onPress([&gui, &window, userName, &start, &backEndRun] { mainMenu(gui, window, userName, start, backEndRun); });
    gui.add(buttonBack);
}

void mainMenu(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool& start, bool& backEndRun)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    gui.remove(gui.get("ButtonStart"));

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    userName->setSize({ "100%", "8%" });
    userName->setPosition({ "0.52%", "1.01%" });
    userName->setRenderer(menuTheme.getRenderer("LabelUserName"));

    auto picture = tgui::Picture::create("../src/main-ui.png");
    picture->setSize({ "100%", "100%" });
    gui.add(picture);

    auto buttonPlay = tgui::Button::create("");
    buttonPlay->setSize({ "18.7%", "33.3%" });
    buttonPlay->setPosition({ "30.9%", "16%" });
    buttonPlay->onPress([&gui, &window, userName, &start, &backEndRun] { simulationScreen(gui, window, userName, start, backEndRun); });
    buttonPlay->setRenderer(menuTheme.getRenderer("ButtonPlay"));
    gui.add(buttonPlay, "ButtonPlay");

    auto buttonAboutUs = tgui::Button::copy(buttonPlay);
    buttonAboutUs->setPosition({ "50.4%", "16%" });
    buttonAboutUs->setRenderer(menuTheme.getRenderer("ButtonSettings"));
    buttonAboutUs->onPress([&gui, &window, userName, &start, &backEndRun] { aboutUsScreen(gui, window, userName, start, backEndRun); });
    gui.add(buttonAboutUs);

    auto buttonHelp = tgui::Button::copy(buttonPlay);
    buttonHelp->setPosition({ "30.9%", "50.7%" });
    buttonHelp->setRenderer(menuTheme.getRenderer("ButtonHelp"));
    gui.add(buttonHelp);

    auto buttonQuit = tgui::Button::copy(buttonPlay);
    buttonQuit->setPosition({ "50.4%", "50.7%" });
    buttonQuit->setRenderer(menuTheme.getRenderer("ButtonQuit"));
    buttonQuit->onPress([&] { window.close(); });
    gui.add(buttonQuit);

    gui.add(userName);
}

int regUser(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password, tgui::EditBox::Ptr confirmPass)
{
    std::string registerUsername = username->getText().toStdString();
    std::string registerPassword = password->getText().toStdString();
    std::string registerConfirmation = confirmPass->getText().toStdString();

    return registerUser(registerUsername, registerPassword, registerConfirmation);
}

void registerScreen(tgui::BackendGui& gui, sf::RenderWindow& window, bool& start, bool& backEndRun)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    auto background = tgui::Picture::create("../src/register-ui.png");
    background->setSize({ "100%", "100%" });
    gui.add(background);

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    auto userName = tgui::Label::create();

    // Register widgets
    auto registerUsername = tgui::EditBox::create();
    registerUsername->setSize({ "28.12%", "10.10%" });
    registerUsername->setPosition({ "35.9%", "21.71%" });
    registerUsername->setDefaultText("Enter Username");
    registerUsername->setRenderer(menuTheme.getRenderer("LoginField"));
    gui.add(registerUsername);

    auto registerPassword = tgui::EditBox::copy(registerUsername);
    registerPassword->setPosition({ "35.9%", "38.88%" });
    registerPassword->setPasswordCharacter('*');
    registerPassword->setDefaultText("Enter Password");
    gui.add(registerPassword);

    auto confirmPassword = tgui::EditBox::copy(registerPassword);
    confirmPassword->setPosition({ "35.9%", "57.07%" });
    confirmPassword->setDefaultText("Confirm Password");
    gui.add(confirmPassword);

    auto buttonConfirm = tgui::Button::create();
    buttonConfirm->setSize({ "18.22%", "10.10%" });
    buttonConfirm->setPosition({ "40.88%", "72.42%" });
    buttonConfirm->setRenderer(menuTheme.getRenderer("ConfirmButton"));
    gui.add(buttonConfirm);

    buttonConfirm->onPress([=] { userName->setText(registerUsername->getText()); });
    buttonConfirm->onPress([registerUsername, registerPassword, confirmPassword, &gui, &window, userName, &start, &backEndRun]
        {
            switch (regUser(registerUsername, registerPassword, confirmPassword))
            {
            case 0:
                mainMenu(gui, window, userName, start, backEndRun);
                break;
            case 1:
                // Write: Password is too short
                break;
            case 2:
                // Write: Password needs to have numbers
                break;
            case 3:
                // Write: Password needs to have symbols(~`!@#$%^&*()_-+={[}]|:;\'<,>.?/\")
                break;
            case 4:
                // Write: Password's don't match
                break;
            }
        });
}

bool logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::string loginUsername = username->getText().toStdString();
    std::string loginPassword = password->getText().toStdString();

    return loginUser(loginUsername, loginPassword);
}

void logInScreen(tgui::BackendGui& gui, sf::RenderWindow& window, bool& start, bool& backEndRun)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    auto picture = tgui::Picture::create("../src/log-in-ui.png");
    picture->setSize({ "100%", "100%" });
    gui.add(picture);

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    auto userName = tgui::Label::create();

    // Log in widgets
    auto logInUsername = tgui::EditBox::create();
    logInUsername->setSize({ "28.1%", "9.2%" });
    logInUsername->setPosition({ "35.9%", "24.1%" });
    logInUsername->setDefaultText("Username");
    logInUsername->setRenderer(menuTheme.getRenderer("LoginField"));
    gui.add(logInUsername);

    auto logInPassword = tgui::EditBox::copy(logInUsername);
    logInPassword->setPosition({ "35.9%", "40.8%" });
    logInPassword->setPasswordCharacter('*');
    logInPassword->setDefaultText("Password");
    gui.add(logInPassword);

    auto buttonLogin = tgui::Button::create("LOG IN");
    buttonLogin->setSize({ "15.3%", "9.2%" });
    buttonLogin->setPosition({ "42.3%", "57.4%" });
    buttonLogin->setRenderer(menuTheme.getRenderer("LoginButton"));
    gui.add(buttonLogin);

    buttonLogin->onPress([=] { userName->setText(logInUsername->getText()); });
    buttonLogin->onPress([logInUsername, logInPassword, &gui, &window, userName, &start, &backEndRun]
        {
            if (logIn(logInUsername, logInPassword))
                mainMenu(gui, window, userName, start, backEndRun);
            /* Write: User doesn't exist!*/
        });

    auto buttonRegister = tgui::Button::create("REGISTER");
    buttonRegister->setSize({ "15.3%", "5.5%" });
    buttonRegister->setPosition({ "42.3%", "68.5%" });
    buttonRegister->setRenderer(menuTheme.getRenderer("RegisterButton"));
    gui.add(buttonRegister);

    buttonRegister->onPress([&gui, &window, &start, &backEndRun] { registerScreen(gui, window, start, backEndRun); });
}

bool displayWindow(tgui::BackendGui& gui, sf::RenderWindow& window, bool& start, bool& backEndRun)
{
    try
    {
        logInScreen(gui, window, start, backEndRun);
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}