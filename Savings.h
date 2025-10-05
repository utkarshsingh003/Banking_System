#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Savings :public Account
{
	friend ostream& operator<<(ostream& os, const Savings& rhs);
	friend istream& operator>>(istream& is, Savings& rhs);

private:
	string name;
	int age;
	string PAN;
	double balance;
	long int Acc_no;
	double int_rate;

public:
	Savings();
	bool deposit(double amount, double i);
	bool withdraw(double amount);
};
