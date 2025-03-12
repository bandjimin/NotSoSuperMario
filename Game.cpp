/*AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros
*/

#include "Game.h"

// Following code is from ChatGPT with the following prompt: "please help me debug this piece of code"
/*Game::Game(int L, int N, int V, int coins, int nothing, int goombas, int koopas, int mushrooms){
    w = World(L, N, V, coins, nothing, goombas, koopas, mushrooms);
    m = Mario(w.getWorld(), L, N, V);
    gameLog = ""; // Correct usage of gameLog
}
Imagine world.cpp and mario.cpp are perfect, why would int main(){
    Game g = Game(2,3,2,20,20,20,20,20);
    return 0;
}cause an error
*/
Game::Game(int L, int N, int V, int coins, int nothing, int goombas, int koopas, int mushrooms)
    : w(L, N, V, coins, nothing, goombas, koopas, mushrooms), // Use initialization list for `w` and `m`
      m(w.getWorld(), L, N, V) { // otherwise there is undefined behavior
    b = Battle();
    gameLog = "";  // Correctly initialize gameLog
}
// End of ChatGPT debugging


Game::Game(){
    w = World(2,3,2,20,20,20,20,20);
    m = Mario(w.getWorld(),2,3,2);
    b = Battle();
    gameLog = "";
}

Game::~Game(){

}

void Game::playGame(){ // initializes World and Mario and has them interact together
    addToGameLog(w.getString());
    std::string lstring; // location string
    lstring += "Mario is starting in position: (";
    lstring += std::to_string(m.getRow());
    lstring += ",";
    lstring += std::to_string(m.getCol());
    lstring += ")\n==========\n";
    addToGameLog(lstring);
    while (true){
        std::string moveResult = m.move(); // makes move & added space for formatting
        m.generateNextMove(); // generates the next move // int nextMove = std::rand() % 4;
        addToGameLog(m.printLocation());
        /*kkwkk
        ggkkg
        xcmmg
        bmggH
        kxkmg
        ==========
        Level: 0. */
        addToGameLog(moveResult);
        interactWithWorld();
        /*Mario is at position: (3,4). Mario is at power level 0. Mario visited an empty space. Mario has 3 lives left. Mario has 0 coins. Mario will move UP. 
        ==========
        */
        if (m.getLives() <= 0){ // mario has no more lives
            std::string gameover = "";
            gameover += "Mario has no more lives.\nGAMEOVER :(";
            addToGameLog(gameover);
            break;
        } else if (m.getLevel() == w.getL()){
            std::string gameover = "";
            gameover += "Mario saved the princess.\nGAMEOVER :)";
            addToGameLog(gameover);
            break;
        }
    }
}        

void Game::addToGameLog(std::string logEntry){ // SETTER: input for game log
    gameLog += logEntry;
}

void Game::interactWithWorld(){
    std::string logEntry;

    char object = m.encounter();

    bool isWin = b.isWin(object);

    //add objects
    switch (object){
        case 'c':
            m.addCoins();
            logEntry = "Mario collected a coin. ";
            w.emptySpace(m.getLevel(),m.getRow(),m.getCol()); // if Mario picks up a coin it is no longer on the grid
            break; // using break prevents fallthrough
        case 'g':
            if (isWin){
                logEntry = "Mario came across a Goomba and won! ";
                w.emptySpace(m.getLevel(),m.getRow(),m.getCol()); // if defeated goomba goes poof
            } else {
                m.losePowerLevel();
                logEntry = "Mario came across a Goomba and lost! :( ";
            }
            break;
        case 'k':
            if (isWin){
                logEntry = "Mario came across a Koopa and won! ";
                w.emptySpace(m.getLevel(),m.getRow(),m.getCol()); // if defeated koopa goes poof
            } else {
                m.losePowerLevel();
                logEntry = "Mario came across a Koopa and lost! :( ";
            }
            break;
        case 'b':
            if (isWin){
                logEntry = "Mario came across The Boss and won! ";
                m.nextLevel(); // 
            } else{
                int currentLevel = m.getPowerLevel();
                for (int i = 0; i < 2; i++){ //loop is for the two power levels
                    if (currentLevel > 0){ 
                        m.losePowerLevel();
                    } else { 
                        m.losePowerLevel();
                        break;
                    }
                }
                logEntry = "Mario came across The Boss and lost! :( ";
            }
            break;
        case 'm':
            m.addPowerLevel();
            logEntry = "Mario collected a mushroom and powered up a level. ";
            w.emptySpace(m.getLevel(),m.getRow(),m.getCol()); // if you eat a mushroom it's no longer on the grid
            break;
        case 'x':
            logEntry = "Mario moved to an empty space. ";
            break;
        case 'w':
            logEntry = "Mario warped. ";
            m.nextLevel();
            break;
        default:
            logEntry = "Mario came across an unknown object. ";
    }

    //updates log entry
    logEntry += "Mario has " + std::to_string(m.getLives()) + " lives left. ";
    // Mario has 0 coins. 
    logEntry += "Mario has " + std::to_string(m.getCoins()) + " coins. ";
    // Mario will move UP.
    logEntry += "Mario will " + m.getDirection() + ".\n";
    logEntry += "==========\n";
    addToGameLog(logEntry);
}

std::string Game::output(){; // GETTER: outputs game log when game is played
    return gameLog;
}

/*
// TEST CASE works without FileProcessor & main.cpp
int main(){
    Game g = Game(2,3,2,20,20,20,20,20);
    g.playGame();
    std::cout << g.output() << std::endl;
    return 0;
}
*/
