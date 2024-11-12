#include <Arduino.h>
#include "inputs.h"

void initInputs() {
    pinMode(VERT_PIN_1, INPUT);
    pinMode(HORZ_PIN_1, INPUT);
    pinMode(SW_BTN_1, INPUT_PULLUP);

    // Joystick 2
    pinMode(VERT_PIN_2, INPUT);
    pinMode(HORZ_PIN_2, INPUT);
    pinMode(SW_BTN_2, INPUT_PULLUP);

    // Restart btn
    pinMode(BTN_1, INPUT_PULLUP);
}

bool isBtnPressed(int pin) {
    return digitalRead(pin) == LOW;
}

JoystickPos getJoystickPosition(int pinX, int pinY) {
    JoystickPos pos;
    pos.x = map(analogRead(pinX), 0, 4095, -1, 1);
    pos.y = map(analogRead(pinY), 0, 4095, -1, 1);

    return pos;
}