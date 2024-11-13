#include <iostream>
#include <string>
#include "display.h"
#include "inputs.h"
#include "menu.h"

// Timer variables
unsigned long previousMillis = 0;  // Stores the last time the display was updated
const long interval = 20;  // Interval to update the display (in milliseconds)
const long menuInterval = 200;  // Interval to update the menu display (in milliseconds)

void setup() {
    initDisplay();
    initInputs();
	initMenu();
}

void loop() {
	unsigned long currentMillis = millis();

	if (isMainMenu) {
		if (currentMillis - previousMillis >= menuInterval) {
			previousMillis = currentMillis;
			clearDisplay();

			showMainMenu();

			JoystickPos pos1 = getJoystickPosition(HORZ_PIN_1, VERT_PIN_1);

			updateMainMenu(pos1.y);
		}

		if (isBtnPressed(SW_BTN_2)) {
			selectMode();
		}
	} else if (is1PMenu || is2PMenu) {
		if (currentMillis - previousMillis >= menuInterval) {
			previousMillis = currentMillis;
			clearDisplay();

			if (is1PMenu) {
				show1PMenu();
			} else {
				show2PMenu();
			}

			JoystickPos pos1 = getJoystickPosition(HORZ_PIN_1, VERT_PIN_1);

			updateGameMenu(pos1.y);
		}
	}

	bool isBackBtnPressed = isBtnPressed(BTN_1);
	if (isBackBtnPressed) {
		backToMenu();
	}
}
