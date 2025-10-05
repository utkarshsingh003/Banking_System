#include "Account.h"
#include "Savings.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

ostream& operator<<(ostream& os, const Savings& rhs)
{
	os << "[Account holder's name: " << rhs.name << " Age: " << rhs.age << " PAN no: " << rhs.PAN << " Account no: " << rhs.Acc_no << " Interest Rate: " << rhs.int_rate <<" Balance: " <<rhs.balance << " ]";
	return os;
}
istream& operator>>(istream& is, Savings& rhs)
{
	char n{};
	bool valid{true};

	cout << "Enter Your name: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(is, rhs.name);

	cout << "\nEnter your age: ";
	is >> rhs.age;
	if (rhs.age < 18 )
	{
		cout << "You cant open a savings account!" << endl;
		valid = false;
		return is;
	}
	
	cout << "\nDo you have a PAN card [Y/N] ";
	is >> n;

	if (n == 'Y' || n == 'y')
	{
		cout << "Enter your PAN number: ";
		is >> rhs.PAN;
	}

	else
	{
		cout << "\nYou cant open a savings account!" << endl;
		valid = false;
		return is;
	}

	cout << "\nDeposit atleast 500$ to open account ";
	is >> rhs.balance;

	if (rhs.balance < 500)
	{
		cout << "\nYou cant open savings account!" << endl;
		valid = false;
		return is;
	}
	if(valid == true)
		cout << "Account opened successfully!" << endl;

	return is;
}


Savings::Savings()
	:name{ "None" }, age{ 0 }, PAN{ "None" }, balance{ 0.0 }, int_rate{ 0.06 }
{
	srand(static_cast<unsigned int>(time(0)));
	Acc_no = rand() % 100000 + 1;
}
bool Savings::deposit(double amount, double i)
{
	long int acc{};
	cout << "Enter Your account number: ";
	cin >> acc;

	if(acc != Acc_no)
		cout << "Sorry Account number doesn't match!" << endl;

	else
	{
		if (amount <= 0)
			return false;

		else
		{
			amount = amount + (amount * i) / 100;
			balance += amount;
			return true;
		}
	}
}

bool Savings::withdraw(double amount)
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

