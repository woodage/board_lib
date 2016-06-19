//
// Created by robbie on 15-6-2016.
//
///@file
#ifndef DUE_BEEPER_MAGNET_H
#define DUE_BEEPER_MAGNET_H
#include <hwlib-due.hpp>

/// The electro magnet is supported by a 36V battery ( 4 x 9 Volt). Magnet can turn on with relay.
/// In the code you will send output to the relay. Relay is controlling the electro magnet.


class magnet {
private:
    due::pin_in_out pin;
public:
    /// default constructor. Requires a digital pin
    magnet(due::pin_in_out & pin);

    // Turn on the magnet

    void turn_on();

    /// Turn of the magnet
    void turn_off();
};


#endif //DUE_BEEPER_MAGNET_H
