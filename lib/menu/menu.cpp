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

GameData onePGameList[] = {
    {"Flappy Bird", "flappy-bird"},
    {"Tetris", "tetris"},
    {"Sliding Puzzle", "sliding-puzzle"},
    {"Snake", "snake"},
    {"Maze", "maze"},
    {"Break Wall", "break-wall"},
    {"Duck Hunt", "duck-hunt"},
    {"Stack", "stack"},
};

GameData twoPGameList[] = {
    {"Pong", "pong"},
    {"Battleship", "battleship"},
    {"Math Quiz", "math-quiz"},
    {"Hand Slaps", "hand-slaps"},
    {"Tanks", "tanks"},
    {"Ship Battle", "ship-battle"},
    {"Guard & Thief", "guard-thief"},
    {"Robot Arena", "robot-arena"},
};

int modeLength = sizeof(modes) / sizeof(modes[0]);
int onePLength = sizeof(onePGameList) / sizeof(onePGameList[0]);
int twoPLength = sizeof(twoPGameList) / sizeof(twoPGameList[0]);

int selectedMode;

GameData selectedGame;
int selectedGameNum;
int gameStartIdx;
int gameEndIdx;

void initMenu() {
	isMainMenu = true;
	is1PMenu = false;
	is2PMenu = false;

    selectedMode = 0;
    selectedGameNum = 0;

    gameStartIdx = 0;
    gameEndIdx = 2;
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
        selectedGame = onePGameList[selectedGameNum];
    } else if (selectedMode == 1) {
        is2PMenu = true;
        selectedGame = twoPGameList[selectedGameNum];
    }

    isMainMenu = false;
}

void show1PMenu() {
    renderText(textX, 1, "1 Player Games");

    for (int i = gameStartIdx; i <= gameEndIdx; i++) {
        int y = (i - gameStartIdx) * 15 + 21;
        renderText(SCREEN_WIDTH / 2 - 36, y, onePGameList[i].name);

        if (selectedGameNum == i) {
            int y0 = (i - gameStartIdx) * 15 + 25;
            int y1 = (i - gameStartIdx) * 15 + 31;
            int y2 = (i - gameStartIdx) * 15 + 29;

            renderTriangle(textX - 10, y0, textX - 10, y1, textX - 4, y2, true);
        }
    }

    renderDisplay();
}

void show2PMenu() {
    renderText(textX, 1, "2 Players Games");
    
    for (int i = gameStartIdx; i <= gameEndIdx; i++) {
        int y = (i - gameStartIdx) * 15 + 21;
        renderText(SCREEN_WIDTH / 2 - 36, y, twoPGameList[i].name);

        if (selectedGameNum == i) {
            int y0 = (i - gameStartIdx) * 15 + 25;
            int y1 = (i - gameStartIdx) * 15 + 31;
            int y2 = (i - gameStartIdx) * 15 + 29;

            renderTriangle(textX - 10, y0, textX - 10, y1, textX - 4, y2, true);
        }
    }
    
    renderDisplay();
}

void updateGameMenu(int val) {
    if (selectedMode == 0) {
        selectedGameNum += val;
        selectedGameNum = constrain(selectedGameNum, 0, onePLength - 1);

        if (selectedGameNum < gameStartIdx && val == -1) {
            gameStartIdx = selectedGameNum;
            
            gameStartIdx = constrain(gameStartIdx, 0, onePLength - 3);
            gameEndIdx = selectedGameNum + 2;
        } else if (selectedGameNum > 2 && val == 1) {
            gameStartIdx = selectedGameNum - 2;
            gameEndIdx = selectedGameNum;
            
            gameEndIdx = constrain(gameEndIdx, 2, onePLength - 1);
        }
    } else {
        selectedGameNum += val;
        selectedGameNum = constrain(selectedGameNum, 0, twoPLength - 1);

        if (selectedGameNum < gameStartIdx && val == -1) {
            gameStartIdx = selectedGameNum;
            
            gameStartIdx = constrain(gameStartIdx, 0, twoPLength - 3);
            gameEndIdx = selectedGameNum + 2;
        } else if (selectedGameNum > 2 && val == 1) {
            gameStartIdx = selectedGameNum - 2;
            gameEndIdx = selectedGameNum;
            
            gameEndIdx = constrain(gameEndIdx, 2, twoPLength - 1);
        }
    }
}

void backToMenu() {
    if (is1PMenu || is2PMenu) {
        is1PMenu = false;
        is2PMenu = false;
        isMainMenu = true;
    }
}