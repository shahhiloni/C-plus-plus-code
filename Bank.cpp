#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void showMenu()
{
    cout << "\n==============================" << endl;
    cout << "       ATM MANAGEMENT SYSTEM" << endl;
    cout << "==============================" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Bank Statement" << endl;
    cout << "5. Change PIN" << endl;
    cout << "6. Exit" << endl;
    cout << "==============================" << endl;
}

int main()
{
    int pin = 1234;
    int enteredPin;
    int choice;

    double balance = 10000.00;
    double amount;

    // Transaction storage
    string transactionType[100];
    double transactionAmount[100];
    double transactionBalance[100];

    int transactionCount = 0;

    double totalCredit = 0;
    double totalDebit = 0;

    int attempts = 0;

    cout << "==============================" << endl;
    cout << "        WELCOME TO ATM" << endl;
    cout << "==============================" << endl;

    // PIN verification
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
            cout << "Attempts remaining: "
                 << 3 - attempts << endl;
        }
    }

    if (attempts == 3)
    {
        cout << "\nYour account is blocked." << endl;
        return 0;
    }

    // ATM menu
    while (true)
    {
        showMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

            case 1:
    cout << "\n===== CHECK BALANCE =====" << endl;
    cout << "Current Balance: " << fixed << setprecision(2)
         << balance << endl;
    break;

            case 2:

                cout << "\nEnter amount to deposit: Rs. ";
                cin >> amount;

                if (amount > 0)
                {
                    balance = balance + amount;

                    // Store transaction
                    transactionType[transactionCount] = "Credit";
                    transactionAmount[transactionCount] = amount;
                    transactionBalance[transactionCount] = balance;

                    transactionCount++;


                    totalCredit = totalCredit + amount;

                    cout << "\nAmount deposited successfully!" << endl;
                    cout << "Updated Balance: Rs. "
                         << balance << endl;
                }
                else
                {
                    cout << "Invalid amount!" << endl;
                }

                break;


            case 3:

                cout << "\nEnter amount to withdraw: Rs. ";
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

                    // Store transaction
                    transactionType[transactionCount] = "Debit";
                    transactionAmount[transactionCount] = amount;
                    transactionBalance[transactionCount] = balance;

                    transactionCount++;

                    // Update total debit
                    totalDebit = totalDebit + amount;

                    cout << "\nPlease collect your cash." << endl;
                    cout << "Remaining Balance: Rs. "
                         << balance << endl;
                }

                break;

            case 4:
    cout << "\n===================== BANK PASSBOOK STATEMENT =====================" << endl;

    if (transactionCount == 0)
    {
        cout << "No transactions available." << endl;
    }
    else
    {
        cout << fixed << setprecision(2);

        cout << left
             << setw(6)  << "S.No"
             << setw(14) << "Particulars"
             << right
             << setw(14) << "Credit"
             << setw(14) << "Debit"
             << setw(16) << "Balance"
             << endl;

        cout << "---------------------------------------------------------------------" << endl;

        for (int i = 0; i < transactionCount; i++)
        {
            cout << left
                 << setw(6)  << i + 1
                 << setw(14) << transactionType[i]
                 << right;

            if (transactionType[i] == "Credit")
            {
                cout << setw(14) << transactionAmount[i]
                     << setw(14) << "-";
            }
            else
            {
                cout << setw(14) << "-"
                     << setw(14) << transactionAmount[i];
            }

            cout << setw(16) << transactionBalance[i] << endl;
        }

        cout << "---------------------------------------------------------------------" << endl;

        cout << left << setw(20) << "Total Credit"
             << right << setw(20) << totalCredit << endl;
        cout << left << setw(20) << "Total Debit"
             << right << setw(20) << totalDebit << endl;
        cout << left << setw(20) << "Closing Balance"
             << right << setw(20) << balance << endl;
    }

    cout << "=====================================================================" << endl;

    break;
            case 5:
            {
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

                        cout << "PIN changed successfully!"
                             << endl;
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
            }
            case 6:

                cout << "\nThank you for using our ATM!" << endl;
                cout << "Please take your card." << endl;

                return 0;


            default:

                cout << "\nInvalid choice!" << endl;
                cout << "Please select between 1 and 6."
                     << endl;
        }
    }

    return 0;
}