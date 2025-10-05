#include "Account.h"
#include "Trust.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

ostream& operator<<(ostream& os, const Trust& rhs)
{
	os << "[Account holder's name: " << rhs.name << " Age: " << rhs.age << " PAN no: " << rhs.PAN << " Account no: " << rhs.Acc_no << " Balance: " << rhs.balance << " ]";
	return os;
}
istream& operator>>(istream& is, Trust& rhs)
{
	char n{};
	bool valid{ true };

	cout << "Enter Your name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(is, rhs.name);

	cout << "\nEnter your age: ";
	is >> rhs.age;
	if (rhs.age < 18 )
	{
		cout << "You cant open a trust account" << endl;
		valid = false;
		return is;
	}


	cout << "\nDo you have a PAN card [Y/N] ";
	is >> n;

	if (n == 'Y' || n == 'y')
	{
		cout << "Enter your PAN number:";
		is >> rhs.PAN;
	}

	else
	{
		cout << "\nYou cant open a trust account" << endl;
		valid = false;
		return is;
	}

	cout << "\nDeposit atleast 500$ to open account ";
	is >> rhs.balance;

	if (rhs.balance < 500)
	{
		cout << "\nYou cant open a trust account" << endl;
		valid = false;
		return is;
	}
	if (valid == true)
		cout << "Account opened successfully!" << endl;

	return is;
}


Trust::Trust()
	:name{ "None" }, age{ 0 }, PAN{ "None" }, balance{ 0.0 }, limits{ 0 }
{
	srand(static_cast<unsigned int>(time(0)));
	Acc_no = rand() % 100000 + 1;
}
bool Trust::deposit(double amount)
{
	long int acc{};
	cout << "Enter your account number: ";


	if (acc != Acc_no)
		cout << "Sorry Account number doesn't match!" << endl;

	else
	{
		if (amount <= 0)
			return false;

		else if (amount >= 5000)
		{
			amount += 50;
			balance += amount;
			return true;
		}

		else
		{
			balance += amount;
			return true;
		}
	}
}

bool Trust::withdraw(double amount)
{
	long int acc{};
	cout << "Enter your account number: ";
	cin >> acc;

	if (acc != Acc_no)
		cout << "Sorry Account number doesn't match!" << endl;

	else
	{
		while (limits <= 3)
		{
			if (amount <= 0)
				return false;

			else
			{
				balance += amount;
				limits += 1;
				return true;
			}
		}
		return false;
	}
}

