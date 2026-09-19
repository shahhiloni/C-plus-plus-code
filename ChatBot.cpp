#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

// ===============================
// TRANSACTION STRUCTURE
// ===============================

struct Transaction
{
    string date;
    string type;
    string description;
    double amount;
};

// ===============================
// BANK ACCOUNT CLASS
// ===============================

class BankAccount
{
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    vector<Transaction> transactions;

    // Constructor
    BankAccount(string name, string number, double initialBalance)
    {
        accountHolder = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // ===============================
    // GET CURRENT DATE
    // ===============================

    string getCurrentDate()
    {
        time_t now = time(0);
        tm *localTime = localtime(&now);

        string date =
            to_string(localTime->tm_mday) + "-" +
            to_string(localTime->tm_mon + 1) + "-" +
            to_string(localTime->tm_year + 1900);

        return date;
    }

    // ===============================
    // ACCOUNT DETAILS
    // ===============================

    void accountDetails()
    {
        cout << "\n====================================\n";
        cout << "          ACCOUNT DETAILS\n";
        cout << "====================================\n";

        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : Rs. " << fixed
             << setprecision(2) << balance << endl;
    }

    // ===============================
    // CHECK BALANCE
    // ===============================

    void checkBalance()
    {
        cout << "\n------------------------------------\n";
        cout << "Current Balance: Rs. "
             << fixed << setprecision(2)
             << balance << endl;
        cout << "------------------------------------\n";
    }

    // ===============================
    // DEPOSIT
    // ===============================

    void deposit()
    {
        double amount;

        cout << "\nEnter deposit amount: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
            return;
        }

        balance += amount;

        Transaction transaction;

        transaction.date = getCurrentDate();
        transaction.type = "Credit";
        transaction.description = "Cash Deposit";
        transaction.amount = amount;

        transactions.push_back(transaction);

        cout << "\nDeposit successful!\n";
        cout << "New Balance: Rs. " << balance << endl;
    }

    // ===============================
    // WITHDRAW
    // ===============================

    void withdraw()
    {
        double amount;

        cout << "\nEnter withdrawal amount: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
            return;
        }

        if (amount > balance)
        {
            cout << "\nInsufficient balance!\n";
            return;
        }

        balance -= amount;

        Transaction transaction;

        transaction.date = getCurrentDate();
        transaction.type = "Debit";
        transaction.description = "Cash Withdrawal";
        transaction.amount = amount;

        transactions.push_back(transaction);

        cout << "\nWithdrawal successful!\n";
        cout << "Remaining Balance: Rs. "
             << balance << endl;
    }

    // ===============================
    // TRANSFER MONEY
    // ===============================

    void transferMoney()
    {
        string receiver;
        double amount;

        cout << "\nEnter receiver account number: ";
        cin >> receiver;

        cout << "Enter transfer amount: Rs. ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Invalid amount.\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amount;

        Transaction transaction;

        transaction.date = getCurrentDate();
        transaction.type = "Debit";
        transaction.description =
            "Transfer to " + receiver;

        transaction.amount = amount;

        transactions.push_back(transaction);

        cout << "\nTransfer successful!\n";
        cout << "Amount transferred: Rs. "
             << amount << endl;

        cout << "Remaining Balance: Rs. "
             << balance << endl;
    }

    // ===============================
    // TRANSACTION HISTORY
    // ===============================

    void transactionHistory()
    {
        cout << "\n============================================================\n";
        cout << "                  TRANSACTION HISTORY\n";
        cout << "============================================================\n";

        if (transactions.empty())
        {
            cout << "No transactions available.\n";
            return;
        }

        cout << left
             << setw(15) << "Date"
             << setw(15) << "Type"
             << setw(30) << "Description"
             << setw(15) << "Amount"
             << endl;

        cout << "------------------------------------------------------------\n";

        for (Transaction t : transactions)
        {
            cout << left
                 << setw(15) << t.date
                 << setw(15) << t.type
                 << setw(30) << t.description
                 << "Rs. " << fixed
                 << setprecision(2)
                 << t.amount
                 << endl;
        }
    }

    // ===============================
    // MONTHLY STATEMENT
    // ===============================

    void monthlyStatement()
    {
        int month;
        int year;

        cout << "\nEnter month (1-12): ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;

        string monthString = to_string(month);
        string yearString = to_string(year);

        cout << "\n============================================================\n";
        cout << "                   MONTHLY BANK STATEMENT\n";
        cout << "============================================================\n";

        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Month          : " << month
             << "/" << year << endl;

        cout << "------------------------------------------------------------\n";

        bool found = false;

        double totalCredit = 0;
        double totalDebit = 0;

        for (Transaction t : transactions)
        {
            // Date format: DD-MM-YYYY

            size_t firstDash = t.date.find("-");
            size_t secondDash = t.date.find("-", firstDash + 1);

            string transactionMonth =
                t.date.substr(
                    firstDash + 1,
                    secondDash - firstDash - 1
                );

            string transactionYear =
                t.date.substr(secondDash + 1);

            if (stoi(transactionMonth) == month &&
                stoi(transactionYear) == year)
            {
                found = true;

                cout << left
                     << setw(15) << t.date
                     << setw(15) << t.type
                     << setw(30) << t.description
                     << "Rs. "
                     << fixed << setprecision(2)
                     << t.amount
                     << endl;

                if (t.type == "Credit")
                    totalCredit += t.amount;
                else
                    totalDebit += t.amount;
            }
        }

        if (!found)
        {
            cout << "No transactions found for this month.\n";
        }

        cout << "------------------------------------------------------------\n";

        cout << "Total Credit : Rs. "
             << totalCredit << endl;

        cout << "Total Debit  : Rs. "
             << totalDebit << endl;

        cout << "Current Balance : Rs. "
             << balance << endl;

        cout << "============================================================\n";
    }

    // ===============================
    // SAVE STATEMENT TO TEXT FILE
    // ===============================

    void saveStatement()
    {
        int month;
        int year;

        cout << "\nEnter month (1-12): ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;

        string filename =
            "Bank_Statement_" +
            to_string(month) +
            "_" +
            to_string(year) +
            ".txt";

        ofstream file(filename);

        if (!file)
        {
            cout << "Unable to create statement file.\n";
            return;
        }

        file << "====================================================\n";
        file << "                    ABC BANK\n";
        file << "               MONTHLY BANK STATEMENT\n";
        file << "====================================================\n\n";

        file << "Account Holder : "
             << accountHolder << "\n";

        file << "Account Number : "
             << accountNumber << "\n";

        file << "Statement      : "
             << month << "/" << year << "\n\n";

        file << "----------------------------------------------------\n";

        file << left
             << setw(15) << "Date"
             << setw(15) << "Type"
             << setw(30) << "Description"
             << "Amount\n";

        file << "----------------------------------------------------\n";

        double totalCredit = 0;
        double totalDebit = 0;

        for (Transaction t : transactions)
        {
            size_t firstDash = t.date.find("-");
            size_t secondDash =
                t.date.find("-", firstDash + 1);

            string transactionMonth =
                t.date.substr(
                    firstDash + 1,
                    secondDash - firstDash - 1
                );

            string transactionYear =
                t.date.substr(secondDash + 1);

            if (stoi(transactionMonth) == month &&
                stoi(transactionYear) == year)
            {
                file << left
                     << setw(15) << t.date
                     << setw(15) << t.type
                     << setw(30) << t.description
                     << "Rs. "
                     << fixed
                     << setprecision(2)
                     << t.amount
                     << "\n";

                if (t.type == "Credit")
                    totalCredit += t.amount;
                else
                    totalDebit += t.amount;
            }
        }

        file << "----------------------------------------------------\n";

        file << "Total Credit : Rs. "
             << totalCredit << "\n";

        file << "Total Debit  : Rs. "
             << totalDebit << "\n";

        file << "Closing Balance : Rs. "
             << balance << "\n";

        file << "====================================================\n";

        file.close();

        cout << "\nStatement generated successfully!\n";
        cout << "File: " << filename << endl;
    }
};


// ======================================================
// CHATBOT
// ======================================================

void chatbot(BankAccount &account)
{
    string command;

    cout << "\n\n============================================\n";
    cout << "          BANKING CHATBOT\n";
    cout << "============================================\n";

    cout << "You can type:\n";
    cout << "  balance\n";
    cout << "  account\n";
    cout << "  deposit\n";
    cout << "  withdraw\n";
    cout << "  transfer\n";
    cout << "  transactions\n";
    cout << "  statement\n";
    cout << "  save statement\n";
    cout << "  help\n";
    cout << "  bye\n";

    while (true)
    {
        cout << "\nYou: ";
        cin.ignore();
        getline(cin, command);

        if (command == "balance")
        {
            cout << "Bot: ";
            account.checkBalance();
        }

        else if (command == "account")
        {
            account.accountDetails();
        }

        else if (command == "deposit")
        {
            account.deposit();
        }

        else if (command == "withdraw")
        {
            account.withdraw();
        }

        else if (command == "transfer")
        {
            account.transferMoney();
        }

        else if (command == "transactions")
        {
            account.transactionHistory();
        }

        else if (command == "statement")
        {
            account.monthlyStatement();
        }

        else if (command == "save statement")
        {
            account.saveStatement();
        }

        else if (command == "help")
        {
            cout << "\nBot: Available commands:\n";

            cout << "1. balance\n";
            cout << "2. account\n";
            cout << "3. deposit\n";
            cout << "4. withdraw\n";
            cout << "5. transfer\n";
            cout << "6. transactions\n";
            cout << "7. statement\n";
            cout << "8. save statement\n";
            cout << "9. bye\n";
        }

        else if (command == "bye")
        {
            cout << "\nBot: Thank you for using ABC Bank!\n";
            break;
        }

        else
        {
            cout << "Bot: Sorry, I don't understand that command.\n";
            cout << "Bot: Type 'help' to see available commands.\n";
        }
    }
}


// ======================================================
// MAIN
// ======================================================

int main()
{
    BankAccount account(
        "Hiloni Shah",
        "XXXXXX1234",
        25000
    );

    // Sample transactions
    Transaction t1;

    t1.date = "01-09-2026";
    t1.type = "Credit";
    t1.description = "Salary";
    t1.amount = 50000;

    account.transactions.push_back(t1);

    Transaction t2;

    t2.date = "05-09-2026";
    t2.type = "Debit";
    t2.description = "ATM Withdrawal";
    t2.amount = 5000;

    account.transactions.push_back(t2);

    Transaction t3;

    t3.date = "10-09-2026";
    t3.type = "Debit";
    t3.description = "Online Shopping";
    t3.amount = 2500;

    account.transactions.push_back(t3);

    chatbot(account);

    return 0;
}