AUTHOR INFO
Full name: Benjamin Kamden Chan & Noslen Cruz-Muniz
Student ID: 2454913 & 2447745
Chapman Email: benchan@chapman.edu & cruzmuniz@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: Programming Assignment 2 - Not So Super Mario Bros

ERRORS
No known errors

RUNNING INSTRUCTIONS
g++ Battle.cpp Mario.cpp World.cpp Game.cpp FileProcessor.cpp main.cpp
./a.out spec.txt log.txt


Following code is from ChatGPT:
    Game::Game(int L, int N, int V, int coins, int nothing, int goombas, int koopas, int mushrooms){
        w = World(L, N, V, coins, nothing, goombas, koopas, mushrooms);
        m = Mario(w.getWorld(), L, N, V);
        gameLog = ""; // Correct usage of gameLog
    }

Here is the prompt: 
    Imagine world.cpp and mario.cpp are perfect, why would int main(){
        Game g = Game(2,3,2,20,20,20,20,20);
        return 0;
    } 
    cause an error


SOURCES
I also used the following links as reference (also listed in the code file):
    - geekforgeeks for syntax in certain areas
    - ChatGPT for debugging
        - asked chat what a segmentation error was
        - how to fix error 
    - https://www.geeksforgeeks.org/learn-data-structures-and-algorithms-dsa-tutorial/?ref=home-articlecards
    - https://www.sololearn.com/en/Discuss/3182508/what-is-the-meaning-of-explain-in-simple-words-data-structure
    - https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault
    - https://www.geeksforgeeks.org/segmentation-fault-c-cpp/
    - https://stackoverflow.com/questions/3718998/fixing-segmentation-faults-in-c
    - https://canvas.chapman.edu/courses/67557/files/6486470?module_item_id=2221446
    - https://www.geeksforgeeks.org/check-if-each-row-and-column-of-nn-grid-contains-all-numbers-from-1-to-n/
    - https://www.reddit.com/r/mathematics/comments/v3tgpx/dont_understand_why_n_n_1_2/
    
