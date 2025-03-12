/*AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros
*/

#include "World.h"

World::World(int L, int N, int V, int coins, int nothing, int goombas, int koopas, int mushrooms){
    // Declaring an array of matrices
    srand(static_cast<unsigned>(time(0)));
    this->world = new char**[L];
    for (int i = 0; i < L; i++){ 
        world[i] = new char*[N]; // each matrix has N rows
        for (int j = 0; j < N; j++){
            world[i][j] = new char[N]; // each matrix has N columns;
        }
    } // i.e. world[0][0][0] is the first world and the top right of the matrix
    this->L = L;
    this->N = N;
    this->V = V;
    this->coins = coins;
    this->nothing = nothing;
    this->goombas = goombas;
    this->koopas = koopas;
    this->mushrooms = mushrooms;

    worldCreation(); // randomize the world
}

World::World(){
    this->L = 2;
    this->N = 3;
    this->V = 2;
    this->coins = 0;
    this->nothing = 100;
    this->goombas = 0;
    this->koopas = 0;
    this->mushrooms = 0;
    this->world = new char**[L];
    for (int i = 0; i < L; i++){ 
        world[i] = new char*[N]; // each matrix has N rows
        for (int j = 0; j < N; j++){
            world[i][j] = new char[N]; // each matrix has N columns;
        }
    } // i.e. world[0][0][0] is the first world and the top right of the matrix

    worldCreation(); // randomize the world
}

World::~World(){
    for (int i = 0; i < L; i++){ 
        for (int j = 0; j < N; j++){
            delete[] world[i][j];
        }
    }
    for (int i = 0; i < L; i++){
        delete[] world[i];
    }
    delete[] world;
}

int World::getL(){
    return L;
}

void World::emptySpace(int level, int row, int col){
    world[level][row][col] = 'x';
}

char World::populateSpace(){
    int randNum = std::rand() % 100; // num from 0-99
    if (randNum < coins){
        return 'c';
    } else if (randNum < coins + nothing){
        return 'x';
    } else if (randNum < coins + nothing + goombas){
        return 'g';
    } else if (randNum < coins + nothing + goombas + koopas){
        return 'k';
    } else{
        return 'm';
    }
}

char*** World::getWorld(){
    return world;
}

std::string World::getString(){
    std::string print = "";
    for (int i = 0; i < L; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                print += world[i][j][k];
            }
            print += "\n"; // new line for each row
        }
        print += "==========\n"; // separating each world
    }
    return print;
}

void World::worldCreation(){
    // Randomizing the levels
    int a, b, c, d;
    for (int i = 0; i < L; i++){ 
        // Make Green Pipe & Boss
        if (i != L - 1){
            a = std::rand() % N;
            b = std::rand() % N;
            world[i][a][b] = 'w'; // w for warp pipe
        } else {a = N; b = N;} // if no pipe, then invalid so boss can be anywhere
        do{
            c = std::rand() % N;
            d = std::rand() % N;
        }
        while (a == c && b == d);
        world[i][c][d] = 'b'; // b for boss

        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                if (world[i][j][k] == 'w' || world[i][j][k] == 'b'){
                    continue; // doesn't change the pipe or boss placement
                } else {
                    world[i][j][k] = populateSpace();
                }
            }
        }
    }
}

/*
// Test Case of Making World
int main(){
    World w = World(2,5,3,20,20,20,20,20);
    std::cout << w.getString();
    std::cout << std::endl;

    Mario m = Mario(w.getWorld(),2,3,2);
    std::cout << m.encounter() << " at (" << m.getRow() << "," << m.getCol() << ")" << std::endl;
    std::cout << m.getLevel();

    // m.generateNextMove();
    std::cout << m.getDirection() << std::endl;
    std::cout << std::endl;

    std::cout << m.getPowerLevel()<< std::endl;
    m.addPowerLevel();
    std::cout << m.getPowerLevel()<< std::endl;
    m.losePowerLevel();
    std::cout << m.getPowerLevel()<< std::endl;
    std::cout << std::endl;

    std::cout << m.getLives() << std::endl;
    m.loseLife(2);
    std::cout << m.getLives() << std::endl;
    
    std::cout << m.getCoins() << std::endl;
    m.addCoins(); // +1
    std::cout << m.getCoins() << std::endl;

    for (int i = 0; i < 5; i++){
        m.generateNextMove();
        m.move(); // use random number to determine direction
        std::cout << m.getLevel() << std::endl;
    }    
    return 0;
}
*/