#include "Account.h"
#include "Current.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

Current::Current()
	:Account(), limits{0} 
{
	srand(time(0));
	Acc_no = rand() % 100000 + 1;
}
Current::Current(string n, int a, string P, double b)
	:Account{ n,a,P,b }, limits{ 0 }
{
	srand(static_cast<unsigned int>(time(0)));
	Acc_no = rand() % 100000 + 1;
}
bool Current::deposit(double amount)
{
	ofstream out_file{ "Current.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};

	if (Account::withdraw(amount))
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

bool Current::withdraw(double amount)
{
	ofstream out_file{ "Current.txt",ios::app };
	if (!out_file)
	{
		cerr << "Can't open a file!" << endl;
		return false;
	}
	ostringstream oss{};

	while(limits < 10)
	{
		if (Account::withdraw(amount))
		{
			limits++;

			oss << "\nName: " << name
				<< "\nAge: " << age
				<< "\nPAN: " << PAN
				<< "\nWithdrawal limit" << limits
				<< "\nDeposted: " << amount
				<< "\nBalance: " << balance
				<< "\nAccount no.: " << Acc_no << endl;

			out_file << oss.str();

			return true;
		}
		else
			return false;
		
	}
}
void Current::print(ostream& os) const
{
	os << "[Account holder's name: " << name << " Age: "
		<< age << " PAN no: " << PAN << " Account no: "
		<< Acc_no << " Balance: " << balance << " withdrawal limit: " << limits << " ]";
}
