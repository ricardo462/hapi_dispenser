#ifndef Feeder_h
#define Feeder_h

#include "Arduino.h"
#include "Servo.h"

class Feeder {
    Servo left_servo;
    Servo right_servo;
    int left_current_position;
    int right_current_position;
    public: 
        Feeder();
        void attach(Servo left, Servo right, int left_pos, int right_pos);
        void move_stereo_servos(int angle);
        void move_stereo_servos_smoothly(int angle, int step_angle,  int time_delay);
        void feed(int open_time, int angle, int step_angle, int time_delay);
};

#endif