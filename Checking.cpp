#include "Account.h"
#include "Checking.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

Checking::Checking()
	:Account()
{
	srand(time(0));
	Acc_no = rand() % 100000 + 1;
}
Checking::Checking(string n, int a, string P, double b)
	:Account{ n,a,P,b }
{
	srand(static_cast<unsigned int>(time(0)));
	Acc_no = rand() % 100000 + 1;
}
bool Checking::deposit(double amount)
{
	ofstream out_file{ "Checking.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};

	if (Account::deposit(amount))
	{
		oss << "Name: " << name
			<< "\nAge: " << age
			<< "\nPAN: " << PAN
			<< "\nDeposted: " << amount
			<< "\nBalance: " << balance
			<< "\nAccount no.: " << Acc_no << endl;

		out_file << oss.str();

		return true;
	}
	else
		return false;
}

bool Checking::withdraw(double amount)
{
	ofstream out_file{ "Checking.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}

	ostringstream oss{};

	amount -= 1.50;
	if (Account::withdraw(amount))
	{
		oss << "\nName: " << name
			<< "\nAge: " << age
			<< "\nPAN: " << PAN
			<< "\nWithdrawn: " << amount
			<< "\nBalance: " << balance
			<< "\nAccount no.: " << Acc_no << endl;

		out_file << oss.str();

		return true;
	}
	else
		return false;
}

