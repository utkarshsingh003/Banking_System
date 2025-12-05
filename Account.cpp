#include "Account.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Account::Account()
	:name{ "None" }, age{ 0 }, PAN{ "None" }, balance{ 0.0 }
{
	srand(time(0));
	Acc_no = rand() % 100000 + 1;
}
Account::Account(string n, int a, string P, double b)
	:name{ n }, age{ a }, PAN{ P }, balance{ b }
{
    srand(time(0));
    Acc_no = rand() % 100000 + 1;
}
bool Account::deposit(double amount)
{
	long int acc{};
	cout << "Enter Your account number: ";
	cin >> acc;

	if (acc != Acc_no)
		cout << "Sorry Account number doesn't match!" << endl;

	else
	{
		if (amount <= 0)
			return false;

		else
		{
			balance += amount;
			return true;
		}
	}
}
bool Account::withdraw(double amount)
{
	long int acc{};
	cout << "Enter Your account number: ";
	cin >> acc;

	if (acc != Acc_no)
		cout << "Sorry Account number doesn't match!" << endl;

	else
	{
		if (amount > balance)
			return false;

		else
		{
			balance -= amount;
			return true;
		}
	}
}
void Account::print(ostream& os) const
{
	os << "[Account holder's name: " << name << " Age: " << age << " PAN no: " << PAN << " Account no: " << Acc_no << " Balance: " << balance << " ]";
}
void Account::input(istream& is)
{
	char n{};
	bool valid{ true };

	cout << "Enter Your name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(is, name);

	cout << "\nEnter your age: ";
	is >> age;
	if (age < 18)
	{
		cout << "You cant open a trust account" << endl;
		valid = false;
	}


	cout << "\nDo you have a PAN card [Y/N] ";
	is >> n;

	if (n == 'Y' || n == 'y')
	{
		cout << "Enter your PAN number:";
		is >> PAN;
	}

	else
	{
		cout << "\nYou cant open a trust account" << endl;
		valid = false;
	}

	cout << "\nDeposit atleast 500$ to open account ";
	is >> balance;

	if (balance < 500)
	{
		cout << "\nYou cant open a trust account" << endl;
		valid = false;
	}
	if (valid == true)
		cout << "Account opened successfully!" << endl;
}
