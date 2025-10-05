#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include <iostream>
#include <vector>
using namespace std;

//For Savings
void display(vector<Savings>& accounts)
{
	char n;
	cout << "Do you want to display all accounts or one [A/O]: ";
	cin >> n;

	int pos;

	if (n == 'A' || n == 'a')
	{
		for (const auto& acc : accounts)
			cout << acc << endl;
	}

	else if (n == 'O' || n == 'o')
	{
		cout << "\nEnter the idex of the account you want to display: between (0 - "<<accounts.size()-1<<" )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
			cout << accounts[pos] << endl;

		else
			cout << "\nInvalid input!" << endl;
	}
}
void deposit(vector <Savings>& accounts, double amount)
{
	char n;
	cout << "Do you want to deposit in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.deposit(amount, 6))
				cout << "\nDeposited " << amount << " to " << acc << endl;

			else
				cout << "\nFailed to deposit!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to deposit from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].deposit(amount, 6);
			cout << "\nDeposited " << amount << " to " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
void withdraw(vector <Savings>& accounts, double amount)
{
	char n;
	cout << "Do you want to withdraw in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.withdraw(amount))
				cout << "\nWithdrawn " << amount << " from " << acc << endl;

			else
				cout << "\nFailed to withdraw!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to withdraw from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].withdraw(amount);
			cout << "\nWithdrawn " << amount << " from " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}

//for Current
void display(vector <Current>& accounts)
{
	char n;
	cout << "Do you want to display all accounts or one [A/O]: ";
	cin >> n;

	int pos;

	if (n == 'A' || n == 'a')
	{
		for (const auto& acc : accounts)
			cout << acc << endl;
	}

	else if (n == 'O' || n == 'o')
	{
		cout << "\nEnter the idex of the account you want to display: between (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
			cout << accounts[pos] << endl;

		else
			cout << "\nInvalid input!" << endl;
	}
}
void deposit(vector <Current>& accounts,double amount)
{
	char n;
	cout << "Do you want to deposit in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.deposit(amount))
				cout << "\nDeposited " << amount << " to " << acc << endl;

			else
				cout << "\nFailed to deposit!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to deposit from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].deposit(amount);
			cout << "\nDeposited " << amount << " to " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
void withdraw(vector <Current>& accounts, double amount)
{
	char n;
	cout << "Do you want to withdraw in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.withdraw(amount))
				cout << "\nWithdrawn " << amount << " from " << acc << endl;

			else
				cout << "\nFailed to withdraw!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to withdraw from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].withdraw(amount);
			cout << "\nWithdrawn " << amount << " from " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}

//For Checking
void display(vector <Checking>& accounts)
{
	char n;
	cout << "Do you want to display all accounts or one [A/O]: ";
	cin >> n;

	int pos;

	if (n == 'A' || n == 'a')
	{
		for (const auto& acc : accounts)
			cout << acc << endl;
	}

	else if (n == 'O' || n == 'o')
	{
		cout << "\nEnter the idex of the account you want to display: between (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
			cout << accounts[pos] << endl;

		else
			cout << "\nInvalid input!" << endl;
	}
}
void deposit(vector <Checking>& accounts, double amount)
{
	char n;
	cout << "Do you want to deposit in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.deposit(amount))
				cout << "\nDeposited " << amount << " to " << acc << endl;

			else
				cout << "\nFailed to deposit!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to deposit from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].deposit(amount);
			cout << "\nDeposited " << amount << " to " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
void withdraw(vector <Checking>& accounts, double amount)
{
	char n;
	cout << "Do you want to withdraw in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.withdraw(amount))
				cout << "\nWithdrawn " << amount << " from " << acc << endl;

			else
				cout << "\nFailed to withdraw!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to withdraw from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].withdraw(amount);
			cout << "\nWithdrawn " << amount << " from " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}

//for Trust
void display(vector <Trust>& accounts)
{
	char n;
	cout << "Do you want to display all accounts or one [A/O]: ";
	cin >> n;

	int pos;

	if (n == 'A' || n == 'a')
	{
		for (const auto& acc : accounts)
			cout << acc << endl;
	}

	else if (n == 'O' || n == 'o')
	{
		cout << "\nEnter the idex of the account you want to display: between (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
			cout << accounts[pos] << endl;

		else
			cout << "\nInvalid input!" << endl;
	}
}
void deposit(vector <Trust>& accounts, double amount)
{
	char n;
	cout << "Do you want to deposit in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.deposit(amount))
				cout << "\nDeposited " << amount << " to " << acc << endl;

			else
				cout << "\nFailed to deposit!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to deposit from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].deposit(amount);
			cout << "\nDeposited " << amount << " to " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
void withdraw(vector <Trust>& accounts, double amount)
{
	char n;
	cout << "Do you want to withdraw in all accounts or one [A/O]: ";
	cin >> n;

	if (n == 'A' || n == 'a')
	{
		for (auto& acc : accounts)
		{
			if (acc.withdraw(amount))
				cout << "\nWithdrawn " << amount << " from " << acc << endl;

			else
				cout << "\nFailed to withdraw!" << endl;
		}
	}
	else if (n == 'O' || n == 'o')
	{
		int pos;
		cout << "\nEnter the index of the account yo want to withdraw from (0 - " << accounts.size() - 1 << " )";
		cin >> pos;

		if (pos >= 0 && pos < accounts.size())
		{
			accounts[pos].withdraw(amount);
			cout << "\nWithdrawn " << amount << " from " << accounts[pos] << endl;
		}
	}
	else
		cout << "\nInvalid input!" << endl;
}
