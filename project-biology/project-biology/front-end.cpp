#include "front-end.h"
#include "front-to-back-end.h"

unsigned short int days = 1;
std::string mouth = "January";
std::string season = "Winter";
int tempeture = 1;

void updateTextSize(tgui::BackendGui& gui)
{
    const float windowHeight = gui.getView().getRect().height;
    gui.setTextSize(static_cast<unsigned int>(0.04f * windowHeight));
}

void removeLockedOverlay(tgui::BackendGui& gui, tgui::Picture::Ptr pic)
{
    gui.remove(pic);
}

size_t getId(size_t id)
{
    return id;
}

void displayObjectButton(tgui::BackendGui& gui, tgui::Picture::Ptr picOverlay, tgui::Layout2d pos, std::string theme, size_t id)
{
    tgui::Theme objectsTheme{ "../src/objects/objects.txt" };

    auto buttonObject = tgui::Button::create();
    buttonObject->setSize({ "4.68%", "9.09%" });
    buttonObject->setPosition(pos);
    buttonObject->setRenderer(objectsTheme.getRenderer(theme));
    buttonObject->onPress([&gui, picOverlay] { removeLockedOverlay(gui, picOverlay); });
    buttonObject->onPress([=] { getId(id); });
    gui.add(buttonObject);
}

void simulationScreen(tgui::BackendGui& gui, tgui::Label::Ptr userName, bool& start)
{
    gui.removeAllWidgets();

    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    tgui::Theme objectsTheme{ "../src/objects/objects.txt" };

    auto symulationBackground = tgui::Picture::create("../src/sym-ui.png");
    symulationBackground->setSize({ "100%", "100%" });
    gui.add(symulationBackground);

    // Sistem manipulation
    auto buttonStart = tgui::Button::create("");
    buttonStart->setSize({ "8.85%", "17.17%" });
    buttonStart->setPosition({ "1.25%", "80.10%" });
    buttonStart->setRenderer(menuTheme.getRenderer("ButtonStart"));
    buttonStart->onPress([=] { simulation(true, days, mouth, season, tempeture); });

    gui.add(buttonStart);

    auto label = tgui::Label::create();
    label->setText("Time is:");
    label->setPosition({ "10.25%", "81.84%" });
    label->setRenderer(menuTheme.getRenderer("LabelTime"));
    label->setTextSize(16);
    gui.add(label);

    auto buttonExit = tgui::Button::copy(buttonStart);
    buttonExit->setPosition({ "78.95%", "80.10%" });
    buttonExit->setRenderer(menuTheme.getRenderer("ButtonExit"));
    buttonExit->onPress([&gui, userName, &start] { mainMenu(gui, userName, start); });
    gui.add(buttonExit);

    // Locked items

    // First column
    auto grassLocked = tgui::Picture::create("../src/objects/locked.png");
    grassLocked->setSize({ "21.61%", "12.62%" });
    grassLocked->setPosition({ "0.52%", "10.60%" });
    gui.add(grassLocked);

    auto blueberryLocked = tgui::Picture::copy(grassLocked);
    blueberryLocked->setPosition({ "0.52%", "24.24%" });
    gui.add(blueberryLocked);

    auto flowerLocked = tgui::Picture::copy(grassLocked);
    flowerLocked->setPosition({ "0.52%", "37.87%" });
    gui.add(flowerLocked);

    // Second column
    auto grasshopperLocked = tgui::Picture::copy(grassLocked);
    grasshopperLocked->setPosition({ "22.65%", "10.60%" });
    gui.add(grasshopperLocked);

    auto butterflyLocked = tgui::Picture::copy(grassLocked);
    butterflyLocked->setPosition({ "22.65%", "24.24%" });
    gui.add(butterflyLocked);

    auto rabbitLocked = tgui::Picture::copy(grassLocked);
    rabbitLocked->setPosition({ "22.65%", "37.87%" });
    gui.add(rabbitLocked);

    auto beeLocked = tgui::Picture::copy(grassLocked);
    beeLocked->setPosition({ "22.65%", "51.51%" });
    gui.add(beeLocked);

    // Third column
    auto mouseLocked = tgui::Picture::copy(grassLocked);
    mouseLocked->setPosition({ "44.79%", "10.60%" });
    gui.add(mouseLocked);

    auto lizardLocked = tgui::Picture::copy(grassLocked);
    lizardLocked->setPosition({ "44.79%", "24.24%" });
    gui.add(lizardLocked);

    auto owlLocked = tgui::Picture::copy(grassLocked);
    owlLocked->setPosition({ "44.79%", "37.87%" });
    gui.add(owlLocked);

    auto foxLocked = tgui::Picture::copy(grassLocked);
    foxLocked->setPosition({ "44.79%", "51.51%" });
    gui.add(foxLocked);

    auto snakeLocked = tgui::Picture::copy(grassLocked);
    snakeLocked->setPosition({ "44.79%", "65.15%" });
    gui.add(snakeLocked);

    // Fourth column
    auto bearLocked = tgui::Picture::copy(grassLocked);
    bearLocked->setPosition({ "66.92%", "10.60%" });
    gui.add(bearLocked);

    // Object buttons

    // First column
    displayObjectButton(gui, grassLocked, { "89.37%", "4.74%" }, "ButtonObjGrass", 1);
    displayObjectButton(gui, blueberryLocked, { "94.47%", "4.74%" }, "ButtonObjBlueberry", 2);
    displayObjectButton(gui, flowerLocked, { "89.37%", "14.64%" }, "ButtonObjFlower", 3);

    // Second column
    displayObjectButton(gui, grasshopperLocked, { "94.47%", "14.64%" }, "ButtonObjGrasshopper", 4);
    displayObjectButton(gui, butterflyLocked, { "89.37%", "24.54%" }, "ButtonObjButterfly", 5);
    displayObjectButton(gui, rabbitLocked, { "94.47%", "24.54%" }, "ButtonObjRabbit", 6);
    displayObjectButton(gui, beeLocked, { "89.37%", "34.44%" }, "ButtonObjBee", 7);

    // Third column
    displayObjectButton(gui, mouseLocked, { "94.47%", "34.44%" }, "ButtonObjMouse", 8);
    displayObjectButton(gui, lizardLocked, { "89.37%", "44.34%" }, "ButtonObjLizard", 9);
    displayObjectButton(gui, owlLocked, { "94.47%", "44.34%" }, "ButtonObjOwl", 10);
    displayObjectButton(gui, foxLocked, { "89.37%", "54.24%" }, "ButtonObjFox", 11);
    displayObjectButton(gui, snakeLocked, { "94.47%", "54.24%" }, "ButtonObjSnake", 12);

    // Fourth column
    displayObjectButton(gui, bearLocked, { "89.37%", "64.14%" }, "ButtonObjBear", 13);
}

void mainMenu(tgui::BackendGui& gui, tgui::Label::Ptr userName, bool &start)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

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
    buttonPlay->onPress([&gui, userName, &start] { simulationScreen(gui, userName, start); });
    buttonPlay->setRenderer(menuTheme.getRenderer("ButtonPlay"));
    gui.add(buttonPlay);

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
    buttonQuit->onPress([] { return; });
    gui.add(buttonQuit);

    gui.add(userName);
}

void registerScreen(tgui::BackendGui& gui, bool& start)
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
    buttonConfirm->onPress([&gui, userName, &start] { mainMenu(gui, userName, start); });
}

void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::cout << "Username: " << username->getText() << std::endl;
    std::cout << "Password: " << password->getText() << std::endl;

    std::string loginUsername = username->getText().toStdString();
    std::string loginPassword = password->getText().toStdString();

    loginUser(loginUsername, loginPassword);
}

void logInScreen(tgui::BackendGui& gui, bool& start)
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
    buttonLogin->onPress([&gui, userName, &start] { mainMenu(gui, userName, start); });

    auto buttonRegister = tgui::Button::create("REGISTER");
    buttonRegister->setSize({ "15.3%", "5.5%" });
    buttonRegister->setPosition({ "42.3%", "68.5%" });
    buttonRegister->setRenderer(menuTheme.getRenderer("RegisterButton"));
    gui.add(buttonRegister);

    buttonRegister->onPress([&gui, &start] { registerScreen(gui, start); });
}

bool runExample(tgui::BackendGui& gui, bool& start)
{
    try
    {
        logInScreen(gui, start);
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}