#include "front-end.h"



void logIn(tgui::EditBox::Ptr username, tgui::EditBox::Ptr password)
{
    std::cout << "Username: " << username->getText() << std::endl;
    std::cout << "Password: " << password->getText() << std::endl;
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
    buttonLogin->onPress([&gui] { loadWidgets(gui); });

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
    buttonRegister->onPress([&gui] { loadWidgets(gui); });
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