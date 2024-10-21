#include <iostream>
#include <ctime>

class Game{
    /* 
    game logic
    show player 4 numbers
    player selects one number between them
    if player guess correct then win
    other wise lost
    show how many games won and how many lost
    */

private:
    int numbers[4];
    int player_choice;
    int random_number;

public:
    void generate_random_number() {
        srand(time(0));
    }
    
    void random_number_generate_for_guessing() {
        for (int i = 0; i < 4; i++) {
            generate_random_number();
            random_number = rand() % 100;
            numbers[i] = random_number;
        }
    }

    int random_number_generate_for_selecting() {
        random_number = rand() % 5;
        return random_number;
    }

    void show_number() {
        random_number_generate_for_guessing();
        for (int i = 0; i < 4; i++) {
            std::cout << numbers[i] << " ";
        }
    }

    int player_choice_ask() {
        std::cout << "Select a number..." << std::endl;
        std::cin >> player_choice;

        return player_choice;
    }

    void check_choice() {
        player_choice = player_choice_ask();
        if (player_choice == numbers[random_number_generate_for_selecting()]) {
            std::cout << "You Won!" << std::endl;
        }
        else {
            std::cout << "You Lost!" << std::endl;
        }
    }

    void game() {
        show_number();
        check_choice();
    }
};