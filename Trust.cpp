#include "Account.h"
#include "Trust.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

Trust::Trust()
	:Account(), limits{0} 
{
	srand(time(0));
	Acc_no = rand() % 100000 + 1;
}
Trust::Trust(string n, int a, string P, double b)
	:Account{ n,a,P,b }, limits{ 0 }
{
	srand(static_cast<unsigned int>(time(0)));
	Acc_no = rand() % 100000 + 1;
}
bool Trust::deposit(double amount)
{
	ofstream out_file{ "Trust.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};

	if (amount >= 5000)
	{
		amount += 50;
		if (Account::deposit(amount))
		{
			oss << "Name: " << name
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
	else
	{
		if (Account::deposit(amount))
			return true;
		else
			return false;
	}
}

bool Trust::withdraw(double amount)
{
	ofstream out_file{ "Trust.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};

	while (limits < 3)
	{
		if (Account::withdraw(amount))
		{
			limits++;

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
}
void Trust::print(ostream& os) const
{
	os << "[Account holder's name: " << name << " Age: " 
		<< age << " PAN no: " << PAN << " Account no: " 
		<< Acc_no << " Balance: " << balance << " withdrawal limit: " << limits << " ]";
}

