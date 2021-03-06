/*
    Brushed motor

    Supported drivers: L298N, L9110S, MX1508, TA6586, TB6612.
    
    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
    GitHub: https://github.com/kurskov/Arduino-BrushedMotor
    Version: 1.0.0

    MIT license
*/

#ifndef _DK_BrushedMotor_h
#define _DK_BrushedMotor_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

class BrushedMotor {
    public:
        BrushedMotor(uint8_t pinA, uint8_t pinB, uint8_t pinC = 255);

        // Runs motor with set speed.
        // Changes speed if motor is running.
        // If you set the value as 0, the motor will stop.
        // Sign of speed value sets turn direction:
        // - positive is forward
        // - negative is backward
        void run(int16_t speed = 10000);

        // Smooth motor stop.
        void stop();

        // Motor blocking.
        // Sets pins A and B as HIGH.
        // If used pin C (PWM), it sets as LOW.
        void brake();

        // State of the motor.
        // Returns one of three chooses:
        //  1 - motor rotates forward
        //  0 - motor stopped
        // -1 - motor rotates backward
        int8_t getState();

    private:
        int16_t _speed = 0;
        uint8_t _pinA; 
        uint8_t _pinB; 
        uint8_t _pinC; // used for 3-wire connection
};

#endif // _DK_BrushedMotor_h
