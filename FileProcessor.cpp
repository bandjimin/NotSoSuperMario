/*AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros
*/

#include "FileProcessor.h"
#include <fstream>
#include <iostream>

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){
    
}

void FileProcessor::processFile(std::string inputFile, std::string outputFile){
    int L, N, V; // level, grid size, lives
    int coins, nothing, goombas, koopas, mushrooms; // percent of each
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()){
        std::cout << "could not open the input file" << inputFile << std::endl;
    } else{
        
        inFile >> L; //reads first num in file
        if (L <= 0){
            std::cout << "invalid number of level" << std::endl;
            return;
        }

        inFile >> N;
        if (N <= 0){
            std::cout << "invalid number of grid size" << std::endl;
            return;
        }

        inFile >> V;
        if (V <= 0){
            std::cout << "invalid number of lives" << std::endl;
            return;
        }

        inFile >> coins;
        if (coins < 0 || coins > 100){ //https://www.w3schools.com/cpp/cpp_operators_logical.asp
            std::cout << "invalid coin percent" << std::endl;
            return;
        }

        inFile >> nothing;
        if (nothing < 0 || nothing > 100){ //https://www.w3schools.com/cpp/cpp_operators_logical.asp
            std::cout << "invalid nothing percent" << std::endl;
            return;
        }

        inFile >> goombas;
        if (goombas < 0 || goombas > 100){ //https://www.w3schools.com/cpp/cpp_operators_logical.asp
            std::cout << "invalid goombas percent" << std::endl;
            return;
        }

        inFile >> koopas;
        if (koopas < 0 || koopas > 100){ //https://www.w3schools.com/cpp/cpp_operators_logical.asp
            std::cout << "invalid koopas percent" << std::endl;
            return;
        }

        inFile >> mushrooms;
        if (mushrooms < 0 || mushrooms > 100){ //https://www.w3schools.com/cpp/cpp_operators_logical.asp
            std::cout << "invalid mushroom percent" << std::endl;
            return;
        }


        int total = coins + nothing + goombas + koopas + mushrooms; // total percent
        if (total != 100){
            std::cout << "error! percent must equal 100, however they sum up to 100" << std::endl;
            return; 
        }

        std::ofstream outFile(outputFile); //create new file
        if (!outFile.is_open()) {
            std::cout << "could not open output file" << outputFile << std::endl;
        } else{
            Game g = Game(L, N, V, coins, nothing, goombas, koopas, mushrooms); // constructor
            g.playGame();
            outFile << g.output();
            outFile.close();
        }
        inFile.close();
    }
}