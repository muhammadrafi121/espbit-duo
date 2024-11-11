#include <iostream>
#include <string>
#include "display.h"
#include "inputs.h"

// Check to show menu page
bool isMainMenu;
bool is1PMenu;
bool is2PMenu;

// Check to play, pause & restart game
bool isPlayGame;
bool isGamePaused;
bool isGameOver;

// Timer variables
unsigned long previousMillis = 0;  // Stores the last time the display was updated
const long interval = 20;  // Interval to update the display (in milliseconds)

void setup() {
    initDisplay();
    initInputs();  
}

void loop() {
	unsigned long currentMillis = millis();
	
	if (currentMillis - previousMillis >= interval) {
		previousMillis = currentMillis;

		clearDisplay();

		renderText(10, 10, "Hello ESPBit Duo");

		JoystickPos pos1 = getJoystickPosition(HORZ_PIN_1, VERT_PIN_1);
		std::string x1 = std::to_string(pos1.x);
		renderText(20, 20, x1.c_str());
	}
}
