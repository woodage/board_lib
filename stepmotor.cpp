//
// Created by robbie on 9-6-2016.
//
///@file
#include "stepmotor.h"
#include <stdlib.h>

stepmotor::stepmotor(due::pin_in_out &pin1, due::pin_in_out &pin2, due::pin_in_out &pin3, due::pin_in_out &pin4 ):
    pin1(pin1),
    pin2(pin2),
    pin3(pin3),
    pin4(pin4)
{
    // define the digital pins as output
    pin1.direction_set_output();
    pin2.direction_set_output();
    pin3.direction_set_output();
    pin4.direction_set_output();
}
/*
void stepmotor::turns(float rotations) {
    // if the rotation count is -ve then it is CCW

    bool clockwise = rotations > 0;

    // calculate how many cycles the stepper will have to make
    int cycles = rotations * 512;
    // force the cycle count to be positive
    cycles = abs(cycles);

    // only move if the user specifed an actual movement
    if(rotations != 0)
    {
        if (clockwise)
        {
            // for each cycle
            for (int x=0; x<cycles; x++)
            {
                // for each phase
                for(int y=0; y<8; y++)
                {
                    // go to phase y
                    phaseSelect(y);
                    // pause so the stepper has time to react
                    hwlib::wait_ms(1);
                }
            }
        } else {
            // for each cycle
            for (int x=0; x<cycles; x++)
            {
                // for each phase (backwards for CCW rotation)
                for(int y=7; y>=0; y--)
                {
                    // go to phase y
                    phaseSelect(y);
                    // pause so the stepper has time to react
                    hwlib::wait_ms(1);
                }
            }
        }
    }
    // go to the default state (all poles off) when finished
    phaseSelect(8);
}

void stepmotor::phaseSelect(int phase){
    switch(phase){
        case 0:
            pin1.set(0);
            pin2.set(0);
            pin3.set(0);
            pin4.set(1);
            break;
        case 1:
            pin1.set(0);
            pin2.set(0);
            pin3.set(1);
            pin4.set(1);
            break;
        case 2:
            pin1.set(0);
            pin2.set(0);
            pin3.set(1);
            pin4.set(0);
            break;
        case 3:
            pin1.set(0);
            pin2.set(1);
            pin3.set(1);
            pin4.set(0);
            break;
        case 4:
            pin1.set(0);
            pin2.set(1);
            pin3.set(0);
            pin4.set(0);
            break;
        case 5:
            pin1.set(1);
            pin2.set(1);
            pin3.set(0);
            pin4.set(0);
            break;
        case 6:
            pin1.set(1);
            pin2.set(0);
            pin3.set(0);
            pin4.set(0);
            break;
        case 7:
            pin1.set(1);
            pin2.set(0);
            pin3.set(0);
            pin4.set(1);
            break;
        default:
            pin1.set(0);
            pin2.set(0);
            pin3.set(0);
            pin4.set(0);
            break;
    }
}
*/
void stepmotor::forwards() {
    // 1
    pin4.set(1);
    pin3.set(0);
    pin2.set(0);
    pin1.set(0);
    hwlib::wait_ms(1);
    // 2
    pin4.set(1);
    pin3.set(1);
    pin2.set(0);
    pin1.set(0);
    hwlib::wait_ms(1);
    // 3
    pin4.set(0);
    pin3.set(1);
    pin2.set(0);
    pin1.set(0);
    hwlib::wait_ms(1);
    // 4
    pin4.set(0);
    pin3.set(1);
    pin2.set(1);
    pin1.set(0);
    hwlib::wait_ms(1);
    // 5
    pin4.set(0);
    pin3.set(0);
    pin2.set(1);
    pin1.set(0);
    hwlib::wait_ms(1);
    // 6
    pin4.set(0);
    pin3.set(0);
    pin2.set(1);
    pin1.set(1);
    hwlib::wait_ms(1);
    // 7
    pin4.set(0);
    pin3.set(0);
    pin2.set(0);
    pin1.set(1);
    hwlib::wait_ms(1);
    // 8
    pin4.set(1);
    pin3.set(0);
    pin2.set(0);
    pin1.set(1);
    hwlib::wait_ms(1);

}

void stepmotor::backwards() {
    // 1
    pin1.set(1);
    pin2.set(0);
    pin3.set(0);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 2
    pin1.set(1);
    pin2.set(1);
    pin3.set(0);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 3
    pin1.set(0);
    pin2.set(1);
    pin3.set(0);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 4
    pin1.set(0);
    pin2.set(1);
    pin3.set(1);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 5
    pin1.set(0);
    pin2.set(0);
    pin3.set(1);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 6
    pin1.set(0);
    pin2.set(0);
    pin3.set(1);
    pin4.set(1);
    hwlib::wait_ms(1);
    // 7
    pin1.set(0);
    pin2.set(0);
    pin3.set(0);
    pin4.set(1);
    hwlib::wait_ms(1);
    // 8
    pin1.set(1);
    pin2.set(0);
    pin3.set(0);
    pin4.set(1);
    hwlib::wait_ms(1);
}