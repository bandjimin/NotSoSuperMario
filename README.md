# Not So Super Mario Project
Not So Super Mario Project is a text-based C++ simulation that reimagines Super Mario Bros. using 2D arrays. Players navigate levels, collect power-ups, battle enemies, and try to defeat Bowser through randomized gameplay and strategic encounters.

## AUTHOR INFO
Names: Benjamin Chan & Noslen Cruz-Muniz  
Chapman Emails: benchan@chapman.edu & cruzmuniz@chapman.edu

## RUNNING INSTRUCTIONS
g++ Battle.cpp Mario.cpp World.cpp Game.cpp FileProcessor.cpp main.cpp  
./a.out spec.txt log.txt

## How It's Made:

**Tech used:** C++

This project was built using C++ and focuses on implementing **data structures** like 2D and 3D arrays to create a text-based simulation of Super Mario Bros. The game logic includes random movement, power-ups, enemy encounters, and level progression. The simulation reads from an input file to generate the game world and outputs a detailed log of Mario’s journey through the levels. The biggest challenge was designing the interaction mechanics while adhering to strict constraints, such as avoiding non-primitive data structures.

## Lessons Learned:

Building this project reinforced the importance of designing efficient **algorithms** and structuring a program for clarity and maintainability. Debugging random movement and probability-based encounters provided insight into handling game logic deterministically while maintaining unpredictability in gameplay.

Working in pairs highlighted the value of **collaboration**, version control, and clear communication. We learned how to divide tasks effectively, review each other's code, and ensure consistency in our implementation. Using tools like Live Share in VSCode helped streamline our workflow, and documenting our thought process made it easier to debug and refine the program together.

## SOURCES
I used the following links as reference (also listed in the code file):  
    - https://www.geeksforgeeks.org/learn-data-structures-and-algorithms-dsa-tutorial/?ref=home-articlecards  
    - https://www.sololearn.com/en/Discuss/3182508/what-is-the-meaning-of-explain-in-simple-words-data-structure  
    - https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault  
    - https://www.geeksforgeeks.org/segmentation-fault-c-cpp/  
    - https://stackoverflow.com/questions/3718998/fixing-segmentation-faults-in-c  
    - https://canvas.chapman.edu/courses/67557/files/6486470?module_item_id=2221446  
    - https://www.geeksforgeeks.org/check-if-each-row-and-column-of-nn-grid-contains-all-numbers-from-1-to-n/  
    - https://www.reddit.com/r/mathematics/comments/v3tgpx/dont_understand_why_n_n_1_2/  
