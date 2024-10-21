#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void checkResult(char player_choice, char computer_choice) {
    if (player_choice == computer_choice) {
        cout << "Draw" << endl;
    } else if (player_choice == 'r' && computer_choice == 'p' || player_choice == 'p' && computer_choice == 's' || player_choice == 's' && computer_choice == 'r') 
    {
        cout << "Oh! You Lose!" << endl;
    } else {
        cout << "You Win!" << endl;
    }
}

char computerChoice(){
    int computer_choice;
    srand(time(NULL));
    computer_choice = rand() % 3;

    if (computer_choice == 0) {
        return 'r';
    } else if (computer_choice == 1) {
        return 'p';
    }else {
        return 's';
    }
}

class UI{
private:
    int ascii = 178;
    char ch = ascii;
    char version[4] = "2.8";

public:
    void line(){
        for (int i = 0; i < 30; i++) {
            cout << ch ;
        }
        cout << endl;
    }

    void display(){
        system("cls");

        line();        
        cout << "Rock Paper Scissors Game" << endl;
        cout << "Version - " << version << endl;
        line();
        cout << endl;
        cout << "Enter r for rock, p for paper and s for scissors " << endl;
        cout << "Enter Your Choice: ";
    }

    void result(char player_choice, char computer_choice){
        if (player_choice == computer_choice) {
            cout << "Draw" << endl;
        } else if ( (player_choice == 'r' && computer_choice == 'p') || (player_choice == 'p' && computer_choice == 's') || (player_choice == 's' && computer_choice == 'r')) 
        {
            cout << "Oh! You Lose!" << endl;
        } else {
            cout << "You Win!" << endl;
        }
    }

};



int main() {
    char player_choice;
    char playagain_choice;

    UI ui;

    start:
    ui.display();

    while (1)
    {
        cin >> player_choice;
        if (player_choice == 'r' || player_choice == 'p' || player_choice =='s')
        {
            break;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }

    char computer_choice = computerChoice();


    cout << "Player choice: " << player_choice << endl;
    cout << "Computer choice: " << computer_choice << endl;

    ui.result(player_choice, computer_choice);

    // play again
    cout << "\n\n" << "Do you want to play again?" << endl;
    cout << "Type y for yes and n for no.: ";
    cin >> playagain_choice;
    if (playagain_choice == 'y') {
        goto start;
    } else {
        cout << "Thank you for playing" << endl;
        system("pause");
    }


    return 0;
}

