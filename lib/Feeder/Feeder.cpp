#include "Arduino.h"
#include "Feeder.h"
#include "Servo.h"

Feeder:: Feeder(){
    
}

void Feeder::attach(Servo left, Servo right, int left_pos, int right_pos){
    left_servo = left;
    right_servo = right;
    left_current_position = left_pos;
    right_current_position = right_pos;
    left_servo.write(left_pos);
    right_servo.write(right_pos);
}

void Feeder::move_stereo_servos(int angle){
left_current_position = left_current_position + angle;
right_current_position = right_current_position - angle;
left_servo.write(left_current_position);
right_servo.write(right_current_position);
}

void Feeder::move_stereo_servos_smoothly(int angle, int step_angle,  int time_delay){
int angles_moved = 0;
while (angles_moved < angle){
    move_stereo_servos(step_angle);
    angles_moved = angles_moved + step_angle;
    delay(time_delay);
    }
}

void Feeder::feed(int open_time, int angle, int step_angle, int time_delay){
    move_stereo_servos_smoothly(angle, step_angle, time_delay);
    delay(open_time);
    move_stereo_servos_smoothly(-angle, step_angle, time_delay);
}




/*Feeder::Feeder(){
    public:
        Servo left_servo;
        Servo right_servo;
        int left_current_position;
        int right_current_position;
        Feeder(Servo left, Servo right, int left_pos, int right_pos){
            left_servo = left;
            right_servo = right;
            left_current_position = left_pos;
            right_current_position = right_pos;
            left_servo.write(left_pos);
            right_servo.write(right_pos);  
        }
        void move_stereo_servos(int angle){
            left_current_position = left_current_position + angle;
            right_current_position = right_current_position - angle;
            left_servo.write(left_current_position);
            right_servo.write(right_current_position);
        }

        void move_stereo_servos_smoothly(int angle, int step_angle,  int time_delay){
            int angles_moved = 0;
            while (angles_moved < angle){
                move_stereo_servos(step_angle);
                angles_moved = angles_moved + step_angle;
                delay(time_delay);
            }
        }

        void feed(int open_time, int angle, int step_angle, int time_delay){
            move_stereo_servos_smoothly(angle, step_angle, time_delay);
            delay(open_time);
            move_stereo_servos_smoothly(-angle, step_angle, time_delay);
        }


};
*/