#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Current :public Account
{
	friend ostream& operator<<(ostream& os, const Current& rhs);
	friend istream& operator>>(istream& is, Current& rhs);

private:
	string name;
	int age;
	string PAN;
	double balance;
	long int Acc_no;
	int limits;

public:
	Current();
	bool deposit(double amount);
	bool withdraw(double amount);
};
