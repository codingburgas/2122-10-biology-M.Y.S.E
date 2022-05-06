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

void displayObjectButton(tgui::BackendGui& gui, tgui::Picture::Ptr picOverlay, tgui::Layout2d pos, std::string theme, short int id, std::vector<short int>& choice)
{
    tgui::Theme objectsTheme{ "../src/objects/objects.txt" };

    bool yes = false;

    auto buttonObject = tgui::Button::create();
    buttonObject->setSize({ "4.68%", "9.09%" });
    buttonObject->setPosition(pos);
    buttonObject->setRenderer(objectsTheme.getRenderer(theme));
    buttonObject->onPress([&gui, picOverlay] { removeLockedOverlay(gui, picOverlay); });
    buttonObject->onPress([&yes] { yes = true; });

    if (yes)
        choice[id - 1] = id;

    gui.add(buttonObject);
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

    std::ifstream choiceFiles("../pb.dal/files/choice.txt");
    std::vector<short int> choice;
    i = 0;

    if (is_empty(choiceFiles))
        choice.resize(13, { -1 });
    else {
        choice.resize(13, {});
        while (getline(choiceFiles, textTime, '|')) {
            choice[i] = stoi(textTime);
            ++i;
        }
    }

    choiceFiles.close();
    // Object buttons

    // First column
    displayObjectButton(gui, grassLocked, { "89.37%", "4.74%" }, "ButtonObjGrass", 1, choice);
    displayObjectButton(gui, blueberryLocked, { "94.47%", "4.74%" }, "ButtonObjBlueberry", 2, choice);
    displayObjectButton(gui, flowerLocked, { "89.37%", "14.64%" }, "ButtonObjFlower", 3, choice);

    // Second column
    displayObjectButton(gui, grasshopperLocked, { "94.47%", "14.64%" }, "ButtonObjGrasshopper", 4, choice);
    displayObjectButton(gui, butterflyLocked, { "89.37%", "24.54%" }, "ButtonObjButterfly", 5, choice);
    displayObjectButton(gui, rabbitLocked, { "94.47%", "24.54%" }, "ButtonObjRabbit", 6, choice);
    displayObjectButton(gui, beeLocked, { "89.37%", "34.44%" }, "ButtonObjBee", 7, choice);

    // Third column
    displayObjectButton(gui, mouseLocked, { "94.47%", "34.44%" }, "ButtonObjMouse", 8, choice);
    displayObjectButton(gui, lizardLocked, { "89.37%", "44.34%" }, "ButtonObjLizard", 9, choice);
    displayObjectButton(gui, owlLocked, { "94.47%", "44.34%" }, "ButtonObjOwl", 10, choice);
    displayObjectButton(gui, foxLocked, { "89.37%", "54.24%" }, "ButtonObjFox", 11, choice);
    displayObjectButton(gui, snakeLocked, { "94.47%", "54.24%" }, "ButtonObjSnake", 12, choice);

    // Fourth column
    displayObjectButton(gui, bearLocked, { "89.37%", "64.14%" }, "ButtonObjBear", 13, choice);

    std::fstream choiceFileS("../pb.dal/files/choice.txt");
    for (int i = 0; i < choice.size(); i++)
        choiceFileS << choice[i] << '|';

    choiceFileS.close();
}

void mainMenu(tgui::BackendGui& gui, sf::RenderWindow& window, tgui::Label::Ptr userName, bool &start, bool& backEndRun)
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

    auto buttonSettings = tgui::Button::copy(buttonPlay);
    buttonSettings->setPosition({ "50.4%", "16%" });
    buttonSettings->setRenderer(menuTheme.getRenderer("ButtonSettings"));
    gui.add(buttonSettings);

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
    buttonConfirm->onPress([&gui, &window, userName, &start, &backEndRun] { mainMenu(gui, window, userName, start, backEndRun); });
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
    buttonLogin->onPress(&logIn, logInUsername, logInPassword);
    buttonLogin->onPress([&gui, &window, userName, &start, &backEndRun] { mainMenu(gui, window, userName, start, backEndRun); });

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