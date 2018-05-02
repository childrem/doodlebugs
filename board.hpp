#ifndef BOARD_HPP
#define BOARD_HPP

#include <random>
#include <iostream>

class Critter;

/************************************************************                     
     * RANDOM STARTING POINT FUNCTION I'm pretty partial to using this 
     * kind of setup lately. Extremely simple. Just set this all up in its own 
     * function call (or two) and you're good to go. This will rely on numberOfColumns
     * and numberOfRows ints in Board class
     *******************************************************************/ 
    
    //setting up the Mersenne Twister
    static std::random_device randyEngine;
    static std::mt19937 theTwister(randyEngine());
    
class Board {

    private:
        bool customBoard = false;
        Critter*** gameBoardPtr;
        int numberOfRows;
        int numberOfColumns;

    public:
        bool isCustom();
        void initBoard();
        void printBoard();

        int getXLimit();
        int getYLimit();

        void randomSpawnPoint(Critter* critter);

        ~Board();

};

#endif
