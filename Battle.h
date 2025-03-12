// AUTHOR INFO
// Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
// Student ID: 2454913 & 2447745
// Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
// Course number and section: CPSC-350-03
// Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros


#include <cstdlib>
#include <ctime>

#ifndef BATTLE_H
#define BATTLE_H

// PURPOSE: to produce the result from a given fight with an interactable
// character

class Battle{
    public:
        Battle();
        ~Battle();

        bool isWin(char letter);
};

#endif