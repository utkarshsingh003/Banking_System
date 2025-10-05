#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Checking :public Account
{
	friend ostream& operator<<(ostream& os, const Checking& rhs);
	friend istream& operator>>(istream& is, Checking& rhs);

private:
	string name;
	int age;
	string PAN;
	double balance;
	long int Acc_no;

public:
	Checking();
	bool deposit(double amount);
	bool withdraw(double amount);
};
