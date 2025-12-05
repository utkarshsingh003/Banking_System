#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Savings :public Account
{
private:
	double int_rate;

public:
	Savings();
	Savings(string n, int a, string P, double b);
	virtual bool deposit(double amount);
	virtual bool withdraw(double amount);
};

