#include "front-end.h"

void updateTextSize(tgui::BackendGui& gui)
{
    const float windowHeight = gui.getView().getRect().height;
    gui.setTextSize(static_cast<unsigned int>(0.04f * windowHeight));
}

void showScreen2(tgui::BackendGui& gui)
{
    gui.removeAllWidgets();

    auto button2 = tgui::Button::create("Switch to sceen 1");
    button2->onPress([&gui] { mainMenu(gui); });
    gui.add(button2);
}

void mainMenu(tgui::BackendGui& gui)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    gui.removeAllWidgets();

    auto picture = tgui::Picture::create("../src/ui.png");
    picture->setSize({ "100%", "100%" });
    gui.add(picture);

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    auto buttonPlay = tgui::Button::create("");
    buttonPlay->setSize({ "24.1%", "32.1%" });
    buttonPlay->setPosition({ "25.4%", "17.2%" });
    buttonPlay->onPress([&gui] { showScreen2(gui); });
    buttonPlay->setRenderer(menuTheme.getRenderer("ButtonPlay"));
    gui.add(buttonPlay);

    auto buttonSettings = tgui::Button::create("");
    buttonSettings->setSize({ "24.1%", "32.1%" });
    buttonSettings->setPosition({ "50.5%", "17.2%" });
    buttonSettings->setRenderer(menuTheme.getRenderer("ButtonSettings"));
    gui.add(buttonSettings);

    auto buttonHelp = tgui::Button::create("");
    buttonHelp->setSize({ "24.1%", "32.1%" });
    buttonHelp->setPosition({ "25.4%", "50.6%" });
    buttonHelp->setRenderer(menuTheme.getRenderer("ButtonHelp"));
    gui.add(buttonHelp);

    auto buttonQuit = tgui::Button::create("");
    buttonQuit->setSize({ "24.1%", "32.1%" });
    buttonQuit->setPosition({ "50.5%", "50.6%" });
    buttonQuit->onPress([&gui] { logInScreen(gui); });
    buttonQuit->setRenderer(menuTheme.getRenderer("ButtonQuit"));
    gui.add(buttonQuit);
}

void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::cout << "Username: " << username->getText() << std::endl;
    std::cout << "Password: " << password->getText() << std::endl;

    // I need "username->getText()" and "password->getText()"
    // to be converted to a string so we can call the logIn function
}

void logInScreen(tgui::BackendGui& gui)
{
    updateTextSize(gui);

    gui.onViewChange([&gui] { updateTextSize(gui); });

    auto picture = tgui::Picture::create("../src/login.png");
    picture->setSize({ "100%", "100%" });
    gui.add(picture);

    tgui::Theme menuTheme{ "../src/theme-menu.txt" };

    // Log in widgets
    auto logInUsername = tgui::EditBox::create();
    logInUsername->setSize({ "20%", "6.6%" });
    logInUsername->setPosition({ "10.5%", "28.4%" });
    logInUsername->setDefaultText("Username");
    logInUsername->setRenderer(menuTheme.getRenderer("LoginField"));
    gui.add(logInUsername);

    auto logInPassword = tgui::EditBox::copy(logInUsername);
    logInPassword->setPosition({ "10.5%", "40%" });
    logInPassword->setPasswordCharacter('*');
    logInPassword->setDefaultText("Password");
    gui.add(logInPassword);

    auto buttonLogin = tgui::Button::create("LOG IN");
    buttonLogin->setSize({ "20%", "6.6%" });
    buttonLogin->setPosition({ "10.5%", "65%" });
    buttonLogin->setRenderer(menuTheme.getRenderer("LoginButton"));
    gui.add(buttonLogin);

    buttonLogin->onPress(&logIn, logInUsername, logInPassword);
    buttonLogin->onPress([&gui] { mainMenu(gui); });

    // Register widgets
    auto registerUsername = tgui::EditBox::create();
    registerUsername->setSize({ "20%", "6.6%" });
    registerUsername->setPosition({ "40%", "28.4%" });
    registerUsername->setDefaultText("Username");
    registerUsername->setRenderer(menuTheme.getRenderer("LoginField"));
    gui.add(registerUsername);

    auto registerPassword = tgui::EditBox::copy(registerUsername);
    registerPassword->setPosition({ "40%", "40%" });
    registerPassword->setPasswordCharacter('*');
    registerPassword->setDefaultText("Password");
    gui.add(registerPassword);

    auto buttonRegister = tgui::Button::create("REGISTER");
    buttonRegister->setSize({ "20%", "6.6%" });
    buttonRegister->setPosition({ "40%", "65%" });
    buttonRegister->setRenderer(menuTheme.getRenderer("LoginButton"));
    gui.add(buttonRegister);

    buttonRegister->onPress(&logIn, registerUsername, registerPassword);
    buttonRegister->onPress([&gui] { mainMenu(gui); });
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