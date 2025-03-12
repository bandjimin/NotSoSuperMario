// AUTHOR INFO
// Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
// Student ID: 2454913 & 2447745
// Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
// Course number and section: CPSC-350-03
// Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros

#include "World.h"
#include "Mario.h"

#ifndef GAME_H
#define GAME_H

// PURPOSE: to play the whole game by interacting with the World and Game files

class Game{
    public:
        Game(int L, int N, int V, int coins, int nothing, int goombas, int koopas, int mushrooms);
        ~Game();
        Game(); // FileProcessor gets mad at me when I don't have a default constructor

        void playGame(); // initializes World and Mario and has them interact together
        void addToGameLog(std::string logEntry); // SETTER: input for game log ; temprarily storess info for retrieving 
        void interactWithWorld();
        std::string output(); // GETTER: outputs game log when game is played
    private:
        World w;
        Mario m;
        Battle b;
        std::string gameLog;
};

#endif