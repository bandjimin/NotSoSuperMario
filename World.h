// AUTHOR INFO
// Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
// Student ID: 2454913 & 2447745
// Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
// Course number and section: CPSC-350-03
// Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros

#include <iostream>

// PURPOSE = To create the world with every level and grid
// and to print out the layout at the start of every game
// to show each level like the sample file

#ifndef WORLD_H
#define WORLD_H

class World{
    public: 
        World();
        World(int L, int N, int V, int coins, int nothing, int goombas, int koopas, int mushrooms);
        ~World();

        // to print for the outfile
        std::string getString();
        // generating random world
        void worldCreation();
        // geting the world
        char*** getWorld();
        // getter for num of levels
        int getL();
        // setter for after Mario hits a space or defeats an enemy
        void emptySpace(int level, int row, int col);
    private:
        // used in generating random world
        char populateSpace();
        char*** world;
        int L;
        int N;
        int V;
        int coins;
        int nothing;
        int goombas;
        int koopas;
        int mushrooms;
};

#endif