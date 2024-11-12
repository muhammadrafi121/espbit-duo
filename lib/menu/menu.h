#ifndef MENU_H
    #define MENU_H

    // Check to show menu page
    extern bool isMainMenu;
    extern bool is1PMenu;
    extern bool is2PMenu;

    // Variable for menu page
    extern int selectedMode;
    extern const char* modes[];

    void initMenu();
    void showMainMenu();
    void updateMainMenu(int val);
    void selectMode();
    void show1PMenu();
    void show2PMenu();
    void backToMenu();
#endif