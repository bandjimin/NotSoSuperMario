/*AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros
*/

#include "Mario.h"

Mario::Mario(char*** world, int L, int N, int V)  : world(world), L(L), N(N), 
lives(V), coins(0), powerLevel(0), stageLevel(0){ //  : lives(V), coins(0), powerLevel(0), stageLevel(0)
    location = new int[2]{0,0};
    location[0] = std::rand() % N; // random index in the level grid
    location[1] = std::rand() % N; // num 0 - N-1
    nextMove = 4;
}

Mario::Mario() : lives(0), coins(0), powerLevel(0), stageLevel(0) { //initialize
    location = new int[2]{0,0};
    std::srand(static_cast<unsigned>(std::time(0))); //https://www.ibm.com/docs/en/i/7.3?topic=expressions-static-cast-operator-c-only & http://soundsoftware.ac.uk/c-pitfall-unsigned.html#:~:text=C%20and%20C%2B%2B%20are%20unusual,that%20can%20never%20be%20negative.
}

Mario::~Mario(){
    delete[] location;
}

void Mario::generateNextMove(){
    nextMove = std::rand() % 4; // random direction from 0-3
}

std::string Mario::getDirection(){
    if (lives <= 0){
        return "stay put"; // follows the example log because if dead you can't move anywhere
    }
    switch (nextMove){
        case 0:
            return "move UP";
        case 1:
            return "move DOWN";
        case 2:
            return "move LEFT";
        case 3:
            return "move RIGHT";
        default:
            return "stay put";
    }
}

int Mario::getLevel(){
    return stageLevel;
}

void Mario::nextLevel(){
    stageLevel += 1;
    location[0] = std::rand() % N; // after moving to a new level
    location[1] = std::rand() % N; // the position of mario randomly changes
    nextMove = 4;
}

int Mario::getLives(){
    return lives;
}

void Mario::loseLife(){
    --lives;
}

int Mario::getCoins(){
    return coins;
}

void Mario::addCoins(){
    ++coins;
    if (coins % 20 == 0){
        ++lives; //void Mario add life to see if mario earns extra life
    }
}

int Mario::getPowerLevel(){
    return powerLevel;
}

void Mario::addPowerLevel(){
    if (powerLevel < 2){
        ++powerLevel;
    }
}

void Mario::losePowerLevel(){
    if (powerLevel > 0) {
        --powerLevel;
    } else if (powerLevel == 0){ // if Mario lose a PL while at PL_0 he loses a life
        loseLife();
    }
}
int Mario::getRow(){
    return location[0];
}

int Mario::getCol(){
    return location[1];
}

char Mario::encounter(){
    char encounter = world[stageLevel][location[0]][location[1]];
    if (encounter == 'b'){
        nextMove = 4; // when encountering the boss, Mario stays put until he dies or wins
    }
    return encounter;
}

// string output in form "Mario is at position: (3,4). Mario is at power level 0. " for the Game class
std::string Mario::move(){
    int row = location[0]; //current location
    int col = location[1]; //current location

    //0 = up, 1 = down, 2 = left, 3 = right
    // Following code inspired from https://www.geeksforgeeks.org/check-if-each-row-and-column-of-nn-grid-contains-all-numbers-from-1-to-n/
    // https://www.reddit.com/r/mathematics/comments/v3tgpx/dont_understand_why_n_n_1_2/
    
    switch (nextMove){ //direction of movement
        case 0:
            row = (row - 1 + N) % N; // prevents negative row number when row at 0
            break;
        case 1:
            row = (row + 1) % N;
            break;
        case 2:
            col = (col - 1 + N) % N; // same reasoning as row 101
            break;
        case 3:
            col = (col + 1) % N;
            break;
    }
    // End of inspiration
    location[0] = row; //updates location
    location[1] = col; //updates location
    return "Mario moved to (" + std::to_string(row) + "," + std::to_string(col) + "). "
    + "Mario is at power level " + std::to_string(powerLevel) + ". ";
    //to_string converts values to strings
}

std::string Mario::printLocation(){ // copied from printing the map in the World class
    std::string levelStr;
    for (int i = 0; i < N; ++i){
        for (int t = 0; t < N; ++t){
            if (i == location[0] && t == location[1]){
                levelStr += 'H';
            } else {
                levelStr += world[stageLevel][i][t];
            }
        }
        levelStr += '\n';
    }
    levelStr += "==========\n";
    levelStr += "Level: " + std::to_string(stageLevel + 1) + ". "; // includes the level to the string
    return levelStr; // repeated use in adding to the log file
}