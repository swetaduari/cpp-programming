#include <iostream>
#include <ctime>
#include <string>
using namespace std;


class ATM {
private:
    
    string accountHolderName;
    string address;
    string branch;
    int accountNumber;
    int pin;
    double startingBalance;
    double currentBalance;
    
public:
    
    ATM() {
        accountHolderName = "Sweta Duari";
        address = "Rajkot";
        branch = "babromanraj";
        accountNumber = 5678;
        pin = 12345;
        startingBalance = 60000.0;
        currentBalance = 20000.0;
    }
    

    void displayDateTime();
    void welcomeScreen();
    void helpScreen();
    bool authenticatePin();
    void displayMainMenu();
    void depositCash();
    void withdrawCash();
    void checkBalance();
    void displayAccountInfo();
};


void ATM::displayDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Current date : " << dt << endl;
}

void ATM::welcomeScreen() {
    cout << "\n========================================" << endl;
    cout << "       WELCOME TO ATM" << endl;
    cout << "========================================\n" << endl;
    displayDateTime();
    cout << "\nPress 1 and Then Press Enter to Access Your Account Via Pin Number" << endl;
    cout << "or" << endl;
    cout << "Press 0 and press Enter to get Help." << endl;
    cout << "\nEnter your choice: ";
}

void ATM::helpScreen() {
    cout << "\n========================================" << endl;
    cout << "       ATM ACCOUNT STATUS" << endl;
    cout << "========================================\n" << endl;
    cout << "You must have the correct pin number to access this account." << endl;
    cout << "See your bank representative for assistance during bank opening hours." << endl;
    cout << "\nThanks for your choice today!!" << endl;
    cout << "\nPress any key to continue..." << endl;
}

bool ATM::authenticatePin() {
    int enteredPin;
    int attempts = 1;
    
    cout << "\n========================================" << endl;
    cout << "       ATM ACCOUNT ACCESS" << endl;
    cout << "========================================\n" << endl;
    cout << "Enter Your Acc Pin Access Number! [Only one attempt is allowed]\n" << endl;
    cin >> enteredPin;
    
    // pin check
    if (enteredPin == pin) {
        return true;
    } else {
        cout << "\n========================================" << endl;
        cout << "           THANK YOU" << endl;
        cout << "========================================\n" << endl;
        cout << "You had made your attempt which failed!!!" << endl;
        cout << "No More attempts allowed!! Sorry!!" << endl;
        cout << "\nPress any key to continue..." << endl;
        return false;
    }
}

void ATM::displayMainMenu() {
    cout << "\n========================================" << endl;
    cout << "       ATM Main Menu Screen" << endl;
    cout << "========================================\n" << endl;
    cout << "Enter [1] To Deposit Cash" << endl;
    cout << "Enter [2] To Withdraw Cash" << endl;
    cout << "Enter [3] To Balance Inquiry" << endl;
    cout << "Enter [0] to Exit ATM\n" << endl;
    cout << "PLEASE ENTER A SELECTION AND PRESS RETURN KEY: ";
}

void ATM::displayAccountInfo() {
    cout << "\nThe Names of the Account Holders are: " << accountHolderName << endl;
    cout << "The Account Holders' address is: " << address << endl;
    cout << "The Branch location is: " << branch << endl;
    cout << "Account number: " << accountNumber << endl;
}

void ATM::depositCash() {
    double amount;
    
    cout << "\n========================================" << endl;
    cout << "    ATM ACCOUNT DEPOSIT SYSTEM" << endl;
    cout << "========================================\n" << endl;
    
    displayAccountInfo();
    
    cout << "\nPresent available balance: Rs. " << currentBalance << endl;
    cout << "\nEnter the Amount to be Deposited Rs. ";
    cin >> amount;
    

    currentBalance += amount;
    
    cout << "\nYour new available Balanced Amount is Rs. " << currentBalance << endl;
    cout << "\n# Thank You!" << endl;
    cout << "\nPress any key to Return to the Main Menu..." << endl;
}

void ATM::withdrawCash() {
    double amount;
    
    cout << "\n========================================" << endl;
    cout << "    ATM ACCOUNT WITHDRAWAL" << endl;
    cout << "========================================\n" << endl;
    
    displayAccountInfo();
    
    cout << "\nPresent available balance: Rs. " << currentBalance << endl;
    cout << "\nEnter the Amount to Withdraw Rs. ";
    cin >> amount;
    
    //balance check
    if (amount > currentBalance) {
        cout << "\nInsufficient Available Balance in your account." << endl;
        cout << "Sorry!!" << endl;
    } else {
        currentBalance -= amount;
        cout << "\nYour new available Balanced Amount is Rs. " << currentBalance << endl;
        cout << "\n# Thank You!" << endl;
    }
    
    cout << "\nPress any key to continue..." << endl;
}

void ATM::checkBalance() {
    cout << "\n========================================" << endl;
    cout << "      ATM BALANCE INQUIRY" << endl;
    cout << "========================================\n" << endl;
    
    displayAccountInfo();
    
    cout << "\nStarting Account Balance: Rs. " << startingBalance << endl;
    cout << "Present available balance: Rs. " << currentBalance << endl;
    cout << "\n# Thank You!" << endl;
    cout << "\nPress any key to Return to the Main Menu..." << endl;
}


int main() {
    
    ATM atmMachine;
    int choice;
    bool authenticated = false;
    
    
    atmMachine.welcomeScreen();
    cin >> choice;
    

    if (choice == 1) {
        authenticated = atmMachine.authenticatePin();
        
        
        while (authenticated) {
            atmMachine.displayMainMenu();
            cin >> choice;
            
            
            switch (choice) {
                case 1:
                    atmMachine.depositCash();
                    break;
                case 2:
                    atmMachine.withdrawCash();
                    break;
                case 3:
                    atmMachine.checkBalance();
                    break;
                case 0:
                    cout << "\nThank you for using our ATM service!" << endl;
                    cout << "Have a great day!\n" << endl;
                    authenticated = false;
                    break;
                default:
                    cout << "\nInvalid choice! Please try again." << endl;
            }
        }
    } else if (choice == 0) {
        atmMachine.helpScreen();
    } else {
        cout << "\nInvalid choice! Exiting..." << endl;
    }
    
    return 0;
}