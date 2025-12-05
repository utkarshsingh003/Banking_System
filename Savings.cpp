#include "Account.h"
#include "Savings.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;


Savings::Savings()
	:Account(), int_rate{0.06} 
{
	srand(time(0));
	Acc_no = rand() % 100000 + 1;
}
Savings::Savings(string n, int a, string P, double b)
	:Account{ n,a,P,b },int_rate{0.06} {}
bool Savings::deposit(double amount)
{
	ofstream out_file{ "Savings.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};

	amount += (amount * int_rate);
	if (Account::deposit(amount))
	{
		oss << "Name: " << name
			<< "\nAge: " << age
			<< "\nPAN: " << PAN
			<< "Interest rate: " << int_rate
			<< "\nDeposited: " << amount
			<< "\nBalance: " << balance
			<< "\nAccount no.: " << Acc_no << endl;

		out_file << oss.str();

		return true;
	}
	else
		return false;
}

bool Savings::withdraw(double amount)
{
	ofstream out_file{ "Savings.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};


	if (Account::withdraw(amount))
	{
		oss << "\nName: " << name
			<< "\nAge: " << age
			<< "\nPAN: " << PAN
			<< "\nInterest rate: " << int_rate
			<< "\nWithdrawn: " << amount
			<< "\nBalance: " << balance
			<< "\nAccount no.: " << Acc_no << endl;

		out_file << oss.str();

		return true;
	}
	else
		return false;
}

