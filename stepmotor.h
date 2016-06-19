//
// Created by robbie on 9-6-2016.
//

///@file
#ifndef DUE_BEEPER_STEPMOTOR_H
#define DUE_BEEPER_STEPMOTOR_H
#include <hwlib-due.hpp>

/// Engine requires stepmotors for changing the magnet position.
class stepmotor {
    private:

    /// private field to store the digital pins.
    due::pin_in_out pin1;
    due::pin_in_out pin2;
    due::pin_in_out pin3;
    due::pin_in_out pin4;
    //void phaseSelect(int phase);

    public:
    /// default constructor. Requires 4 digital pins.
    stepmotor(due::pin_in_out &pin1, due::pin_in_out &pin2, due::pin_in_out &pin3, due::pin_in_out &pin4);
    //void turns(float rotations);

    /// Let the stepmotor step backwards.
    void backwards();

    // Let the stepmotor steps forwards.
    void forwards();

};


#endif //DUE_BEEPER_STEPMOTOR_H
