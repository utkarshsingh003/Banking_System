#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include "Functions.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<Savings> savings_accounts;
    vector<Current> current_accounts;
    vector<Checking> checking_accounts;
    vector<Trust> trust_accounts;

    char choice{};

    do
    {
        cout << "\n***********************" << endl;
        cout << "* O: Open account     *" << endl;
        cout << "* A: Display accounts *" << endl;
        cout << "* D: deposit money    *" << endl;
        cout << "* W: Withdraw money   *" << endl;
        cout << "* Q: Quit             *" << endl;
        cout << "***********************" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 'O' || choice == 'o')
        {
            char n{};
            cout << "Which account do you want to open? "
                << "(S)avings (C)urrent Chec(k)ing (T)rust: ";
            cin >> n;

            if (n == 'S' || n == 's')
            {
                Savings s;
                cin >> s;
                savings_accounts.push_back(s);
            }
            else if (n == 'C' || n == 'c')
            {
                Current c;
                cin >> c;
                current_accounts.push_back(c);
            }
            else if (n == 'K' || n == 'k')
            {
                Checking k;
                cin >> k;
                checking_accounts.push_back(k);
            }
            else if (n == 'T' || n == 't')
            {
                Trust t;
                cin >> t;
                trust_accounts.push_back(t);
            }
            else
            {
                cout << "Unknown account type." << endl;
            }
        }
        else if (choice == 'A' || choice == 'a')
        {
            cout << "Display which account type? (S/C/K/T): ";
            char type;
            cin >> type;

            if (type == 'S' || type == 's') 
                display(savings_accounts);

            else if (type == 'C' || type == 'c') 
                display(current_accounts);

            else if (type == 'K' || type == 'k') 
                display(checking_accounts);

            else if (type == 'T' || type == 't') 
                display(trust_accounts);

            else cout << "Unknown type." << endl;
        }
        else if (choice == 'D' || choice == 'd')
        {
            cout << "Deposit to which account type? (S/C/K/T): ";
            char type;
            cin >> type;

            double amount;
            cout << "Enter amount: ";
            cin >> amount;

            if (type == 'S' || type == 's') 
                deposit(savings_accounts, amount);

            else if (type == 'C' || type == 'c') 
                deposit(current_accounts, amount);

            else if (type == 'K' || type == 'k') 
                deposit(checking_accounts, amount);

            else if (type == 'T' || type == 't') 
                deposit(trust_accounts, amount);

            else cout << "Unknown type." << endl;
        }
        else if (choice == 'W' || choice == 'w')
        {
            cout << "Withdraw from which account type? (S/C/K/T): ";
            char type;
            cin >> type;

            double amount;
            cout << "Enter amount: ";
            cin >> amount;

            if (type == 'S' || type == 's') 
                withdraw(savings_accounts, amount);

            else if (type == 'C' || type == 'c') 
                withdraw(current_accounts, amount);

            else if (type == 'K' || type == 'k') 
                withdraw(checking_accounts, amount);

            else if (type == 'T' || type == 't') 
                withdraw(trust_accounts, amount);

            else cout << "Unknown type." << endl;
        }

    } while (choice != 'Q' && choice != 'q');

    return 0;
}
