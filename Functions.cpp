#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
using namespace std;

void display(unique_ptr<vector<shared_ptr<Account>>>& accounts)
{
	char choice{};
	cout << "Which account do you want to display (S/C/K/T): ";
	cin >> choice;

	if (choice == 'S' || choice == 's')
	{
		for (const auto& acc : *accounts)
		{
			if (dynamic_cast<Savings*>(acc.get()))
				cout << *acc << endl;
		}
	}
	else if (choice == 'C' || choice == 'c')
	{
		for (const auto& acc : *accounts)
		{
			if (dynamic_cast<Current*>(acc.get()))
				cout << *acc << endl;
		}
	}
	else if (choice == 'K' || choice == 'k')
	{
		for (const auto& acc : *accounts)
		{
			if (dynamic_cast<Checking*>(acc.get()))
				cout << *acc << endl;
		}

	}
	else if (choice == 'T' || choice == 't')
	{
		for (const auto& acc : *accounts)
		{
			if (dynamic_cast<Trust*>(acc.get()))
				cout << *acc << endl;
		}
	}
	else
		cout << "Invalid input!" << endl;
}
void deposit(unique_ptr<vector<shared_ptr<Account>>>& accounts)
{
	char n;
	cout << "In which account do you want to deposit(S/C/K/T) or do you want to deposit based on the index(R): ";
	cin >> n;

	double amount{};
	cout << "Enter the amount you want to deposit: ";
	cin >> amount;

	if (n == 'S' || n == 's')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Savings*>(acc.get()))
			{
				if (acc->deposit(amount))
					cout << "\nDeposited " << amount << " to " << *acc << endl;

				else
					cout << "\nFailed to deposit!" << endl;
			}
		}
	}
	else if (n == 'C' || n == 'c')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Current*>(acc.get()))
			{
				if (acc->deposit(amount))
					cout << "\nDeposited " << amount << " to " << *acc << endl;

				else
					cout << "\nFailed to deposit!" << endl;
			}
		}
	}
	else if (n == 'K' || n == 'k')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Checking*>(acc.get()))
			{
				if (acc->deposit(amount))
					cout << "\nDeposited " << amount << " to " << *acc << endl;

				else
					cout << "\nFailed to deposit!" << endl;
			}
		}
	}
	else if (n == 'T' || n == 't')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Trust*>(acc.get()))
			{
				if (acc->deposit(amount))
					cout << "\nDeposited " << amount << " to " << *acc << endl;

				else
					cout << "\nFailed to deposit!" << endl;
			}
		}
	}
	else if (n == 'R' || n == 'r')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to deposit from (0 - " << accounts->size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts->size())
		{
			(*accounts)[pos]->deposit(amount);
			cout << "\nDeposited " << amount << " to " << (*accounts)[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
void withdraw(unique_ptr<vector<shared_ptr<Account>>>& accounts)
{
	char n;
	cout << "from which account do you want to withdraw(S/C/K/T) or do you want to withdraw based on the index(R): ";
	cin >> n;

	double amount{};
	cout << "Enter the amount you want to deposit: ";
	cin >> amount;

	if (n == 'S' || n == 's')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Savings*>(acc.get()))
			{
				if (acc->withdraw(amount))
					cout << "\nWithdrawn " << amount << " from " << *acc << endl;

				else
					cout << "\nFailed to withdraw!" << endl;
			}
		}
	}
	else if (n == 'C' || n == 'c')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Current*>(acc.get()))
			{
				if (acc->withdraw(amount))
					cout << "\nWithdrawn " << amount << " from " << *acc << endl;

				else
					cout << "\nFailed to withdraw!" << endl;
			}
		}
	}
	else if (n == 'K' || n == 'k')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Checking*>(acc.get()))
			{
				if (acc->withdraw(amount))
					cout << "\nWithdrawn " << amount << " from " << *acc << endl;

				else
					cout << "\nFailed to withdraw!" << endl;
			}
		}
	}
	else if (n == 'T' || n == 't')
	{
		for (auto& acc : *accounts)
		{
			if (dynamic_cast<Trust*>(acc.get()))
			{
				if (acc->withdraw(amount))
					cout << "\nWithdrawn " << amount << " from " << *acc << endl;

				else
					cout << "\nFailed to withdraw!" << endl;
			}
		}
	}
	else if (n == 'R' || n == 'r')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to withdraw from (0 - " << accounts->size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts->size())
		{
			(*accounts)[pos]->withdraw(amount);
			cout << "\nWithdrawn " << amount << " from " << (*accounts)[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
void history(unique_ptr<vector<shared_ptr<Account>>>& accounts)
{
	string output{};

	char choice{};
	cout << "Which accounts transaction history do you want to see (S)avings/(C)urrent/Chec(K)ing/(T)rust";
	cin >> choice;

	if (choice == 'S' || choice == 's')
	{
		ifstream in_file{ "Savings.txt" };
		if (!in_file)
		{
			cerr << "Can't open a file!" << endl;
		}
		else
		{
			while (getline(in_file, output))
				cout << output << endl;
		}
	}
	else if (choice == 'C' || choice == 'c')
	{
		ifstream in_file{ "Current.txt" };
		if (!in_file)
		{
			cerr << "Can't open a file!" << endl;
		}
		else
		{
			while (getline(in_file, output))
				cout << output << endl;
		}
	}
	else if (choice == 'K' || choice == 'k')
	{
		ifstream in_file{ "Checking.txt" };
		if (!in_file)
		{
			cerr << "Can't open a file!" << endl;
		}
		else
		{
			while (getline(in_file, output))
				cout << output << endl;
		}
	}
	else if (choice == 'T' || choice == 't')
	{
		ifstream in_file{ "Trust.txt" };
		if (!in_file)
		{
			cerr << "Can't open a file!" << endl;
		}
		else
		{
			while (getline(in_file, output))
				cout << output << endl;
		}
	}
	else
		cout << "Invalid accout to see history!" << endl;
}
