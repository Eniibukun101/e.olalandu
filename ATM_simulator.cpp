#include <iostream>
using namespace std;
//pin=4321
//menu display 
void displaymenu() {
    cout << "======== ATM MENU ========" << endl;
    cout << "1. View Balance" << endl;
    cout << "2. Deposit Cash" << endl;
    cout << "3. Withdraw Cash" << endl;
    cout << "4. Reset PIN" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

//pin verification and attempt count
bool verify_pin(int correct_pin) {
    int entered_pin;
    int attempt_count = 0;  

    while (attempt_count < 3) {
        cout << "Enter your PIN: ";
        cin >> entered_pin;
        
        if (entered_pin == correct_pin) {
            return true;
        } else {
            cout << "Incorrect PIN. Try again." << endl;
            attempt_count++;
        }
    }
    
    //account locked after 3 tries
    return false;
}

//simple balance viewer
double view_balance(double balance) {
    cout << "Your current balance is: N" << balance << endl;
    return balance;  
}

//deposit function 
double deposit_money(double current_balance) { 
    double deposit_amount;
    cout << "Enter amount to deposit: N";
    cin >> deposit_amount;

    if (deposit_amount <= 0) {
        cout << "Invalid deposit amount." << endl;
        return current_balance;  
    } else {
        current_balance = current_balance + deposit_amount;  
        cout << "You have successfully deposited N" << deposit_amount <<"!"<< endl;
        cout << "New balance: N" << current_balance << endl;
        return current_balance;
    }
}

//withdrawal with daily limit check
double withdraw_money(double balance, double daily_limit) {
    double withdrawal_amt;
    cout << "Enter amount to withdraw: N";
    cin >> withdrawal_amt;


    if (withdrawal_amt <= 0) {
        cout << "Invalid withdrawal amount." << endl;
    } 
    else if (withdrawal_amt > balance) {
        cout << "Insufficient balance!" << endl;
    } 
    else if (withdrawal_amt > daily_limit) {
        cout << "You have successfully withdrawn N" << withdrawal_amt << endl;
    }

    cout << "New balance: N" << balance << endl;
    return balance;
}

// pin reset 
int reset_pin(int current_pin) {
    int old_pin_input, new_pin_input;  
    
    cout << "Enter your old PIN: ";
    cin >> old_pin_input;

    if (old_pin_input == current_pin) {
        cout << "Enter new PIN: ";
        cin >> new_pin_input;
        cout << "PIN successfully changed." << endl;
        return new_pin_input;  // Return the new PIN
    } else {
        cout << "Incorrect old PIN. PIN not changed." << endl;
        return current_pin;  // Keep the old PIN
    }
}


int main() {
    // original account setup
    double account_balance = 50000;   
    double withdrawal_limit = 20000;  
    int pin_number = 4321;            

    bool is_pin_verified = verify_pin(pin_number);

    if (!is_pin_verified) {
        cout << "Account Locked. Please contact your bank." << endl;
        return 0; // exit if PIN verification fails
    }

    int user_choice;


    do {
        displaymenu();
        cin >> user_choice;

        switch (user_choice) {
            case 1:
                // View current balance
                account_balance = view_balance(account_balance);
                break;
                
            case 2:
                // Deposit money
                account_balance = deposit_money(account_balance);
                break;
                
            case 3:
                // Withdraw money
                account_balance = withdraw_money(account_balance, withdrawal_limit);
                break;
                
            case 4:
                // Reset PIN
                pin_number = reset_pin(pin_number);
                break;
                
            case 5:
                cout << "Thank you for using our ATM." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please enter 1-5." << endl;
                break;  // Adding break for consistency even though it's not needed
        }

        cout << "------------------------------------" << endl;

    } while (user_choice != 5);

    return 0;
}
