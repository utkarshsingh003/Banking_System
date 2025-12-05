#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
using namespace std;

void display(unique_ptr<vector<shared_ptr<Account>>>& accounts)
{
	char n;
	cout << "Do you want to display all accounts or one [A/O]: ";
	cin >> n;

	int pos;

	if (n == 'A' || n == 'a')
	{
		for (const auto& acc : *accounts)
			cout << *acc << endl;
	}

	else if (n == 'O' || n == 'o')
	{
		cout << "\nEnter the idex of the account you want to display: between (0 - "<<accounts->size()-1<<" )";
		cin >> pos;

		if (pos >= 0 && pos < accounts->size())
			cout << (*accounts)[pos] << endl;

		else
			cout << "\nInvalid input!" << endl;
	}
}
void deposit(unique_ptr<vector<shared_ptr<Account>>>& accounts)
{
	double amount{};
	cout << "Enter the amount you want to deposit: ";
	cin >> amount;

	char n;
	cout << "Do you want to deposit in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : *accounts)
		{
			if (acc->deposit(amount))
				cout << "\nDeposited " << amount << " to " << *acc << endl;

			else
				cout << "\nFailed to deposit!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
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
	double amount{};
	cout << "Enter the amount you want to deposit: ";
	cin >> amount;

	char n;
	cout << "Do you want to withdraw in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : *accounts)
		{
			if (acc->withdraw(amount))
				cout << "\nWithdrawn " << amount << " from " << *acc << endl;

			else
				cout << "\nFailed to withdraw!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
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
