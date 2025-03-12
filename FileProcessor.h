// AUTHOR INFO
// Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
// Student ID: 2454913 & 2447745
// Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
// Course number and section: CPSC-350-03
// Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros

#include <iostream>
#include "Game.h"

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

// PURPOSE: processes the spec file and outputs the game log into the log file

class FileProcessor{
    public:
        FileProcessor();
        ~FileProcessor(); 

        void processFile(std::string inputFile, std::string outputFile);
};

#endif
