// ATM Management System in C++ 

#include <iostream>
using namespace std;

void showMenu()
{
    cout << "\n==============================" << endl;
    cout << "       ATM MANAGEMENT SYSTEM" << endl;
    cout << "==============================" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Change PIN" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================" << endl;
}

int main()
{
    int pin = 1234;
    int enteredPin;
    int choice;

    double balance = 10000.00;
    double amount;

    int attempts = 0;


    cout << "==============================" << endl;
    cout << "        WELCOME TO ATM" << endl;
    cout << "==============================" << endl;

    while (attempts < 3)
    {
        cout << "Enter your 4-digit PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin)
        {
            cout << "\nLogin Successful!" << endl;
            break;
        }
        else
        {
            attempts++;

            cout << "Incorrect PIN!" << endl;
            cout << "Attempts remaining: " << 3 - attempts << endl;
        }
    }

    if (attempts == 3)
    {
        cout << "\nYour account is blocked." << endl;
        cout << "Please contact your bank." << endl;

        return 0;
    }


    while (true)
    {
        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            
                cout << "\nYour current balance is: ₹"
                     << balance << endl;
                break;

            case 2:
                
                cout << "\nEnter amount to deposit: ₹";
                cin >> amount;

                if (amount > 0)
                {
                    balance = balance + amount;

                    cout << "Amount deposited successfully!" << endl;
                    cout << "Updated balance: ₹"
                         << balance << endl;
                }
                else
                {
                    cout << "Invalid amount!" << endl;
                }

                break;

            case 3:
        
                cout << "\nEnter amount to withdraw: ₹";
                cin >> amount;

                if (amount <= 0)
                {
                    cout << "Invalid amount!" << endl;
                }
                else if (amount > balance)
                {
                    cout << "Insufficient balance!" << endl;
                }
                else
                {
                    balance = balance - amount;

                    cout << "Please collect your cash." << endl;
                    cout << "Remaining balance: ₹"
                         << balance << endl;
                }

                break;

            case 4:
                int oldPin;
                int newPin;

                cout << "\nEnter your current PIN: ";
                cin >> oldPin;

                if (oldPin == pin)
                {
                    cout << "Enter your new PIN: ";
                    cin >> newPin;

                    if (newPin >= 1000 && newPin <= 9999)
                    {
                        pin = newPin;

                        cout << "PIN changed successfully!" << endl;
                    }
                    else
                    {
                        cout << "PIN must contain exactly 4 digits."
                             << endl;
                    }
                }
                else
                {
                    cout << "Incorrect current PIN!" << endl;
                }

                break;

            case 5:
                cout << "\nThank you for using our ATM!" << endl;
                cout << "Please take your card." << endl;

                return 0;

            default:
                cout << "\nInvalid choice!" << endl;
                cout << "Please select between 1 and 5." << endl;
        }
    }

    return 0;
}