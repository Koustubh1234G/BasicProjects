// header files
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <random> 
#include <set> 

using namespace std;
// classes for program
// DataBase - store and read values and info from DB
class DataBase{
    public:
    DataBase(){
        loadUsersFromFile();
        loadManagersFromFile();
    }

    // save username and password to users.txt
    void saveUsersToFile(){
        ofstream userfile("users.txt");

        for (const auto& user : users) {
            userfile << user.first << " " << user.second.first << " " << user.second.second << "\n";
        }
        userfile.close();
    }

    bool loadUsersFromFile() {
        ifstream userfile("users.txt");

        if (!userfile)
            return false;
            
        string line;
        while(getline(userfile, line)) {
            istringstream iss(line);
            string username,password;
            if (iss >> username >> password) {
                users[username].first = password;
            }
        }
        userfile.close();
        return true;
    }

    bool loadManagersFromFile() {
        ifstream managerfile("managers.txt");
        if (!managerfile) {
            return false;
        }

        string line;
        while(getline(managerfile, line)) {
            istringstream iss(line);
            string username,password;
            if (iss >> username >> password) {
                managers[username].first = password;
            }
        }
        managerfile.close();
        return true;
    }
    
    void createUser(const string& username, const string& password) {
        users[username] = make_pair(password, 0.0);
        saveUsersToFile();
        cout << "User Created Successfully\n";
    }

    void deleteUser() {
        users.erase(username);
    }

    bool login() {
        string username, password;
        cout << "Enter Username: ";
        cin >> username;

        if (users.find(username) != users.end()) {
            cout << "Enter Password: ";
            cin >> password;

            if (users[username].first == password) {
                return true;
            }
        }

        cout << "Incorrect username or password Try again.\n";
        return false;
    }

    private:
    unordered_map<string, pair<string, double>> users;
    unordered_map<string, string> managers;

};

// Transaction - all transcations info
class Transaction{
    public:
    string type; // tupe of transaction
    double amount;

    Transaction(const string &t, double a) : type(t), amount(a){}
};

// BankAccount - account info and management
class BankAccount{
    public:
    BankAccount(const string &username, DataBase &db) : username(username),open(true),balance(0),database(db) {
        // read account balance from file users.txt
        ifstream file("users.txt");
        string line;
        while(getline(file,line)) {
            istringstream iss(line);
            string storedUsername, storedPassword;
            double storedBalance;
            if (iss >> storedUsername >> storedPassword >> storedBalance){
                balance = storedBalance;
                break;
            }
        }
    }

    void withdraw(double amount) {
        if (open && amount <= balance && amount > 0) {
            balance -= amount;
            transactions.emplace_back("Withdrawl", amount);
            cout << "Successfully withdraw " << amount << "from your account.\n";
            cout << "Your new balance is " << balance << "\n";
            updateBalanceInFile();
        } else {
            cout << "Invalid amount provided or account is deactivated. Contact support for further assistance\n";
        }
    }

    void Deposit(double amount) {
        if (open && amount > 0) {
            balance += amount;
            transactions.emplace_back("Deposit", amount);
            cout << "Successfully deposited $" << amount << " to your account." << endl;
            cout << "Your new balance is: " << balance << endl;
            updateBalanceInFile();
        } else {
            cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
        }
    }

    void PrintAmountSummary() {
        cout << "Account Holder: " << username << "\n"; 
    }
    
};

// BankManager - account manipulation and management
class BankManager{};

// UI
class UI{
    int ascii = 178;
    char ch = ascii;
    char version[4] = "1";

    
public:
    int menu_choice;

    void line(){
        for (int i = 0; i < 40; i++) {
            cout << ch;
        }
        cout << "\n";
    }

    void main_menu() {
        line();
        cout << "Welcome to the banking system Version - " << version << "\n";
        cout << "1. Create account\n";
        cout << "2. Login account\n";
        cout << "3. Manager Login account\n";
        cout << "4. Exit\n";
        line();
        cout << "\n\nChoose Option that you want to perform: ";
    }
};


int main(){
    // object for ui
    UI ui;

    ui.main_menu();
    cin >> ui.menu_choice;
    return 0;
}