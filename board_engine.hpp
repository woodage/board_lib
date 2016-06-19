/// @file
//
// Created by robbie on 9-6-2016.
//

/// library for controlling playground/board game mechanics.

#ifndef DUE_BEEPER_BOARD_ENGINE_H
#define DUE_BEEPER_BOARD_ENGINE_H
#include "stepmotor.h"
#include "magnet.h"
#include <stdlib.h>

/// the main class for controlling the machine/engine
class board_engine {

    private:
        /// start position in grid
        const int start_pos_x = 7;
        const int start_pos_y = 0;

        /// current position in grid
        int current_state_x;
        int current_state_y;

        /// components/modules/sensors
        stepmotor step_hor;
        stepmotor step_ver;
        magnet electro_magnet;

    public:

        /// default constructor
        board_engine(stepmotor & step_hor, stepmotor & step_ver, magnet & electro_magnet):
            step_hor(step_hor),
            step_ver(step_ver),
            electro_magnet(electro_magnet)
        {
            /// set current state on start position
            current_state_x = start_pos_x;
            current_state_y = start_pos_y;
        }

        /// moving function for controlling mechanics
        void up() {
            step_ver.backwards();
        }
        void down() {
            step_ver.forwards();
        }
        void left() {
            step_hor.backwards();
        }
        void right(){
            step_hor.forwards();
        }

        /// Grabbing a magnetic piece from the board.
        void select_piece() {
            electro_magnet.turn_on();
        }

        /// Release a magnetic piece on the board.
        void release_piece() {
            electro_magnet.turn_off();
        }

        /// function to move the magnet X amount of tiles.
        /// @param 1 : amount of tiles
        /// @param 2 : direction (true = right, false = left)
        /// @param 3 : amount of milliseconds to wait after passing 1 tile
        /// @param 4 : calibration variable. Amount of calls needed for engine to pass 1 tile. When using other tiles/distance, Change the (default value) param
        void shift_x(int tiles, bool pos = true, int wait_ms = 1, int calibrate = 270) {

            if(tiles != 0) {
                /// Count amount of taken step to the current y grid.
                for (int x = 0; x < tiles; x++) {

                    for (int i = 0; i < calibrate; i++) {

                        (pos) ? right() : left();
                        hwlib::wait_ms(1);
                    }

                    hwlib::wait_ms(wait_ms);
                }

                /// Count amount of taken step to the current y grid.
                (pos) ? current_state_x += tiles : current_state_x -= tiles;
            }
        };

        /// function to move the magnet X amount of tiles.
        /// @param 1 : amount of tiles
        /// @param 2 : direction (true = right, false = left)
        /// @param 3 : amount of milliseconds to wait after passing 1 tile
        /// @param 4 : calibration variable. Amount of calls needed for engine to pass 1 tile. When using other tiles/distance, Change the (default value) param
        void shift_y(int tiles, bool pos = true, int wait_ms = 1, int calibrate = 270) {

            if(tiles != 0) {
                hwlib::cout << "\n current y : " << current_state_y << "\n";
                /// Loop amount of tiles
                for (int y = 0; y < tiles; y++) {
                    /// Loop till calibration value. When calibration value reached, position is 1 tile moved.
                    for (int i = 0; i < calibrate; i++) {

                        /// When boolean is true, "move" forwards.
                        (pos) ? up() : down();
                    }

                    /// Wait amount of milliseconds when machine passes 1 tile (according the calibration).
                    hwlib::wait_ms(wait_ms);
                }

                /// Count amount of taken step to the current y grid.
                (pos) ? current_state_y += tiles : current_state_y -= tiles;
                hwlib::cout << "\n current y : " << current_state_y << "\n";
            }
        };

        /// Go to this position from current position
        void go_to_grid(int x, int y) {

            /// calculate direction vector
            int x_steps = x - current_state_x;
            int y_steps = y - current_state_y;

            hwlib::cout << "go to function will take x steps :" << x_steps;
            hwlib::cout << "go to function will take y steps :" << y_steps;

            /// decide direction horizontal
            if(x_steps < 0) {
                shift_x(abs(x_steps), false);
            } else {
                shift_x(x_steps);
            }

            /// decide direction vertical
            if(y_steps < 0) {
                shift_y(abs(y_steps), false);
            } else {
                shift_y(y_steps);
            }

            current_state_x = x;
            current_state_y = y;

        }

};

#endif //DUE_BEEPER_BOARD_ENGINE_H