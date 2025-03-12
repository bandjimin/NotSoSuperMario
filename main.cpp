/*AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros
*/

#include <iostream>
#include "FileProcessor.h"

int main(int argc, char** argv) {
    FileProcessor fp;
    if (argc > 2){ // the amount of arguments must exceed 3 otherwise, input and/or output file is unknown
        std::cout << argv[1];
        std::cout << argv[2];
        fp.processFile(argv[1], argv[2]); // argv[0] is the out or exe file
    } else{
        std::cout << "More arguments necessary, add input and output file." << std::endl;
        return 1;
    }
    return 0;
}