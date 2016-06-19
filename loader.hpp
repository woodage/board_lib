///@file

#include "board_engine.hpp"

/// Only function needed for calling the board_engine. When calling the `control` function in `machine` class,
/// function will return board engine with all other parameters in constructor needed. When pins switches,
/// set the values right in function `control`
namespace board_lib{
    class machine {

    public:
        static board_engine control() {

                // for the first stepmotor
                auto step_pin1 = due::pin_in_out(due::pins::d10);
                auto step_pin2 = due::pin_in_out(due::pins::d11);
                auto step_pin3 = due::pin_in_out(due::pins::d12);
                auto step_pin4 = due::pin_in_out(due::pins::d13);

                // for the second stepmotor
                auto step_pin5 = due::pin_in_out(due::pins::d3);
                auto step_pin6 = due::pin_in_out(due::pins::d4);
                auto step_pin7 = due::pin_in_out(due::pins::d5);
                auto step_pin8 = due::pin_in_out(due::pins::d6);

                // pin electro magnet
                auto elec_pin = due::pin_in_out(due::pins::d8);

                // calling the objects
                stepmotor stepmotor1(step_pin1, step_pin2, step_pin3, step_pin4);
                stepmotor stepmotor2(step_pin5, step_pin6, step_pin7, step_pin8);

                magnet electro_magnet(elec_pin);

                board_engine playground(stepmotor1, stepmotor2, electro_magnet);
                return playground;
        }

    };
};