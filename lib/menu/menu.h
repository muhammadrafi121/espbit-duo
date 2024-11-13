#ifndef MENU_H
    #define MENU_H

    // Check to show menu page
    extern bool isMainMenu;
    extern bool is1PMenu;
    extern bool is2PMenu;

    // Variable for menu page
    extern int selectedMode;
    extern const char* modes[];

    struct GameData
    {
        char* name;
        char* slug;
    };

    extern GameData onePGameList[];
    extern GameData twoPGameList[];

    extern GameData selectedGame;

    void initMenu();
    void showMainMenu();
    void updateMainMenu(int val);
    void selectMode();
    void show1PMenu();
    void show2PMenu();
    void updateGameMenu(int val);
    void backToMenu();
#endif