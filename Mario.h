// AUTHOR INFO
// Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
// Student ID: 2454913 & 2447745
// Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
// Course number and section: CPSC-350-03
// Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros

#include <iostream>
#include "Battle.h"

// PURPOSE: Make moves on the board and print out a string correctly formated
// for the output file

#ifndef MARIO_H
#define MARIO_H

class Mario{
    public:
        Mario(); // FileProcessor gets mad when we have no default constructor
        Mario(char*** world, int L, int N, int V);
        ~Mario();
        
        void generateNextMove();
        std::string getDirection();
        int getLevel();
        void nextLevel();
        int getPowerLevel();
        void addPowerLevel();
        void losePowerLevel();
        int getLives();
        void loseLife();
        int getCoins();
        void addCoins(); // +1
        int getRow();
        int getCol();
        char encounter();

        std::string move(); // use random number to determine direction
        std::string printLocation();
    private:
        char*** world;
        int L;
        int N;
        int lives;
        int coins;
        int powerLevel; // init = 0
        int stageLevel; // init = 0
        int* location; // [0,0] [row,col]
        int nextMove;
};



#endif