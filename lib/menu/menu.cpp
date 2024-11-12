#include <iostream>
#include <cmath>
#include "menu.h"
#include "display.h"

bool isMainMenu;
bool is1PMenu;
bool is2PMenu;

int textX = SCREEN_WIDTH / 2 - 36;

const char* modes[] = {
    "1 Player Game",
    "2 Players Game"
};

int modeLength = sizeof(modes) / sizeof(modes[0]);

int selectedMode;

void initMenu() {
	isMainMenu = true;
	is1PMenu = false;
	is2PMenu = false;

    selectedMode = 0;
}

void showMainMenu() {
    renderText(textX, 1, "SELECT MODE");

    for (int i = 0; i < modeLength; i++) {
        int y = i * 15 + 25;
        renderText(SCREEN_WIDTH / 2 - 36, y, modes[i]);
    }

    if (selectedMode == 0) {
        renderTriangle(textX - 10, 29, textX - 10, 35, textX - 4, 32, true);
    } else if (selectedMode == 1) {
        renderTriangle(textX - 10, 44, textX - 10, 50, textX - 4, 47, true);
    }
    
    renderDisplay();
}

void updateMainMenu(int val) {
    selectedMode = abs((selectedMode + val) % modeLength);
}

void selectMode() {
    if (selectedMode == 0) {
        is1PMenu = true;
    } else if (selectedMode == 1) {
        is2PMenu = true;
    }

    isMainMenu = false;
}

void show1PMenu() {
    renderText(textX, 1, "1 Player Games");
    renderDisplay();
}

void show2PMenu() {
    renderText(textX, 1, "2 Players Games");
    renderDisplay();
}

void backToMenu() {
    if (is1PMenu || is2PMenu) {
        is1PMenu = false;
        is2PMenu = false;
        isMainMenu = true;
    }
}