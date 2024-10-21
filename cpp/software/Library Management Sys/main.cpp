#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Library{
    public:
    int id;
    char name[100];
    char author[100];
    char student[100];
    int price;
    int pages;

};

int main(){
    Library lib[20];
    int input;
    int count=0;

    while (input!=5)
    {
        cout << "Enter 1 to input details like id,name, author, student ,price, pages." << endl;
        cout << "Enter 2 to display details." << endl;
        // cout << "Enter 3 to delete details." << endl;
        // cout << "Enter 4 to update details." << endl;
        cout << "Enter 5 to exit." << endl;
        cin >> input;

        switch (input)
        {
        case 1:
            start:
            cout << "Enter book ID" << endl;
            cin >> lib[count].id;
            cout << "Enter book Name" << endl;
            cin >> lib[count].name;
            cout << "Enter book Author" << endl;
            cin >> lib[count].author;
            cout << "Enter student name" << endl;
            cin >> lib[count].student;
            cout << "Enter price" << endl;
            cin >> lib[count].price;
            cout << "Enter pages" << endl;
            cin >> lib[count].pages;
            count++;
            break;
        case 2:
            for(int i= 0; i < count; i++){
                cout <<"Book ID: " << lib[i].id <<endl;
                cout <<"Book Name: " << lib[i].name <<endl;
                cout <<"Book Author: " << lib[i].author <<endl;
                cout <<"Book Student: " << lib[i].student <<endl;
                cout <<"Book Price: " << lib[i].price <<endl;
                cout <<"Book Pages: " << lib[i].pages <<endl;
            }
            break;

        case 5:
            exit(0);
            break;
        
        default:
            cout << "Invalid Value" << endl;
            goto start;
            // break;
        }
    }
    

}