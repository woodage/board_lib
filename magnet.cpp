///@file
//
// Created by robbie on 15-6-2016.
//
#include "magnet.h"

/// magnet default constructor. Requires one digital pins
magnet::magnet(due::pin_in_out &pin):pin(pin) {
    pin.direction_set_output();
}

/// magnet turn on
void magnet::turn_on() {
    pin.set(1);
}

/// magnet turn off
void magnet::turn_off() {
    pin.set(0);
}