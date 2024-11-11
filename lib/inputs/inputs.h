#ifndef INPUTS_H
    #define INPUTS_H

    // Joystick & Button pins
    #define VERT_PIN_1 0
    #define HORZ_PIN_1 1
    #define SW_BTN_1   6

    #define VERT_PIN_2 2
    #define HORZ_PIN_2 3
    #define SW_BTN_2   7

    #define BTN_1 5

    struct JoystickPos
    {
        int x;
        int y;
    };


    void initInputs();
    bool isBtnPressed(int pin);
    JoystickPos getJoystickPosition(int pinX, int pinY);
#endif