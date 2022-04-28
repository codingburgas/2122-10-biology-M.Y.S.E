#include "front-end.h"

void updateTextSize(tgui::BackendGui& gui)
{
    const float windowHeight = gui.getView().getRect().height;
    gui.setTextSize(static_cast<unsigned int>(0.04f * windowHeight));
}

size_t removeLockedOverlay(tgui::BackendGui& gui, tgui::Picture::Ptr pic, size_t id)
{
    gui.remove(pic);

    return id;
}

void simulationScreen(tgui::BackendGui& gui, tgui::Label::Ptr userName)
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
    buttonExit->onPress([&gui, userName] { mainMenu(gui, userName); });
    gui.add(buttonExit);

    // Locked items
    auto grassLocked = tgui::Picture::create("../src/objects/locked.png");
    grassLocked->setSize({ "21.61%", "12.62%" });
    grassLocked->setPosition({ "0.52%", "10.60%" });
    gui.add(grassLocked);

    auto blueberryLocked = tgui::Picture::copy(grassLocked);
    blueberryLocked->setPosition({ "0.52%", "24.24%" });
    gui.add(blueberryLocked);

    auto grasshopperLocked = tgui::Picture::copy(grassLocked);
    grasshopperLocked->setPosition({ "22.65%", "10.60%" });
    gui.add(grasshopperLocked);

    auto rabbitLocked = tgui::Picture::copy(grassLocked);
    rabbitLocked->setPosition({ "22.65%", "37.87%" });
    gui.add(rabbitLocked);

    auto mouseLocked = tgui::Picture::copy(grassLocked);
    mouseLocked->setPosition({ "44.79%", "10.60%" });
    gui.add(mouseLocked);

    auto owlLocked = tgui::Picture::copy(grassLocked);
    owlLocked->setPosition({ "44.79%", "37.87%" });
    gui.add(owlLocked);

    auto foxLocked = tgui::Picture::copy(grassLocked);
    foxLocked->setPosition({ "44.79%", "51.51%" });
    gui.add(foxLocked);

    auto bearLocked = tgui::Picture::copy(grassLocked);
    bearLocked->setPosition({ "66.92%", "10.60%" });
    gui.add(bearLocked);

    // Object buttons
    auto buttonObjRabbit = tgui::Button::create("");
    buttonObjRabbit->setSize({ "4.68%", "9.09%" });
    buttonObjRabbit->setPosition({ "89.37%", "4.74%" });
    buttonObjRabbit->setRenderer(objectsTheme.getRenderer("ButtonObjRabbit"));
    buttonObjRabbit->onPress([&gui, rabbitLocked] { removeLockedOverlay(gui, rabbitLocked, 1); });
    gui.add(buttonObjRabbit);

    auto buttonObjMouse = tgui::Button::copy(buttonObjRabbit);
    buttonObjMouse->setPosition({ "94.47%", "4.74%" });
    buttonObjMouse->setRenderer(objectsTheme.getRenderer("ButtonObjMouse"));
    gui.add(buttonObjMouse);

    auto buttonObjBear = tgui::Button::copy(buttonObjRabbit);
    buttonObjBear->setPosition({ "89.37%", "14.64%" });
    buttonObjBear->setRenderer(objectsTheme.getRenderer("ButtonObjBear"));
    gui.add(buttonObjBear);

    auto buttonObjFox = tgui::Button::copy(buttonObjRabbit);
    buttonObjFox->setPosition({ "94.47%", "14.64%" });
    buttonObjFox->setRenderer(objectsTheme.getRenderer("ButtonObjFox"));
    gui.add(buttonObjFox);

    auto buttonObjGrasshopper = tgui::Button::copy(buttonObjRabbit);
    buttonObjGrasshopper->setPosition({ "89.37%", "24.54%" });
    buttonObjGrasshopper->setRenderer(objectsTheme.getRenderer("ButtonObjGrasshopper"));
    gui.add(buttonObjGrasshopper);

    auto buttonObjOwl = tgui::Button::copy(buttonObjRabbit);
    buttonObjOwl->setPosition({ "94.47%", "24.54%" });
    buttonObjOwl->setRenderer(objectsTheme.getRenderer("ButtonObjOwl"));
    gui.add(buttonObjOwl);
}

void mainMenu(tgui::BackendGui& gui, tgui::Label::Ptr userName)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    userName->setSize({ "10%", "10%" });
    userName->setPosition({ "20%", "20%" });
    userName->setRenderer(menuTheme.getRenderer("LabelUserName"));

    auto picture = tgui::Picture::create("../src/main-ui.png");
    picture->setSize({ "100%", "100%" });
    gui.add(picture);

    auto buttonPlay = tgui::Button::create("");
    buttonPlay->setSize({ "18.7%", "33.3%" });
    buttonPlay->setPosition({ "30.9%", "16%" });
    buttonPlay->onPress([&gui, userName] { simulationScreen(gui, userName); });
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

void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::cout << "Username: " << username->getText() << std::endl;
    std::cout << "Password: " << password->getText() << std::endl;

    std::string loginUsername = username->getText().toStdString();
    std::string loginPassword = password->getText().toStdString();

    loginUser(loginUsername, loginPassword);
}

void logInScreen(tgui::BackendGui& gui)
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
    buttonLogin->onPress([&gui, userName] { mainMenu(gui, userName); });

    auto buttonRegister = tgui::Button::create("REGISTER");
    buttonRegister->setSize({ "15.3%", "5.5%" });
    buttonRegister->setPosition({ "42.3%", "68.5%" });
    buttonRegister->setRenderer(menuTheme.getRenderer("RegisterButton"));
    gui.add(buttonRegister);
}

bool runExample(tgui::BackendGui& gui)
{
    try
    {
        logInScreen(gui);
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}