#include <iostream>

#include "game.h"

class UI{
    char version[3] = "v1";

    int won = 0;
    int lost = 0;

    Game a;

public:
    int main_menu(){
        start:
        int choice;
        std::cout << "Number Guessing Game\n";
        std::cout << "Version " << version << "\n";
        std::cout << "1. Enter Game\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            a.game();
            break;
        case 0:
            return 0;
        
        default:
            std::cout << "Invalid choice";
            goto start;
        }
    }
};