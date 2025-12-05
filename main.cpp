#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include "Functions.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    auto acc = make_unique<vector<shared_ptr<Account>>>();

    char choice{};

    do
    {
        cout << "\n*****************************" << endl;
        cout << "* O: Open account           *" << endl;
        cout << "* A: Display accounts       *" << endl;
        cout << "* D: deposit money          *" << endl;
        cout << "* W: Withdraw money         *" << endl;
        cout << "* H: Transaction History    *" << endl;
        cout << "* Q: Quit                   *" << endl;
        cout << "*****************************" << endl;
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
                acc->push_back(make_shared<Savings>(s));
            }
            else if (n == 'C' || n == 'c')
            {
                Current c;
                cin >> c;
                acc->push_back(make_shared<Current>(c));
            }
            else if (n == 'K' || n == 'k')
            {
                Checking k;
                cin >> k;
                acc->push_back(make_shared<Checking>(k));
            }
            else if (n == 'T' || n == 't')
            {
                Trust t;
                cin >> t;
                acc->push_back(make_shared<Trust>(t));
            }
            else
            {
                cout << "Unknown account type." << endl;
            }
        }
        else if (choice == 'A' || choice == 'a')
        {
            display(acc);
        }
        else if (choice == 'H' || choice == 'h')
        {
            history(acc);
        }
        else if (choice == 'D' || choice == 'd')
        {
            deposit(acc);
        }
        else if (choice == 'W' || choice == 'w')
        {
            withdraw(acc);
        }

    } while (choice != 'Q' && choice != 'q');

    return 0;
}
