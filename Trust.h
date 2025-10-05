
#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Trust :public Account
{
	friend ostream& operator<<(ostream& os, const Trust& rhs);
	friend istream& operator>>(istream& is, Trust& rhs);

private:
	string name;
	int age;
	string PAN;
	double balance;
	long int Acc_no;
	int limits;
public:
	Trust();
	bool deposit(double amount);
	bool withdraw(double amount);
};
