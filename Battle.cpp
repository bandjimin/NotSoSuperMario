/*AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros
*/

#include <iostream>
#include "Battle.h"

Battle::Battle(){
    srand(static_cast<unsigned>(time(0)));
}

Battle::~Battle(){
    
}

bool Battle::isWin(char letter){
    int randNum = std::rand() % 100; // num from 0 - 99
    switch(letter){ // losing consequences
        case 'k':
            if (randNum < 80){
                return true;
            }
            break; // break stops further checks
        case 'g':
            if (randNum < 65){
                return true;
            }
            break;
        case 'b':
            if (randNum < 50){
                return true;
            }
            break;
    }
    return false;
}