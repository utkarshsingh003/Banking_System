#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Checking :public Account
{

public:
	Checking();
	Checking(string n, int a, string P, double b);
	virtual bool deposit(double amount);
	virtual bool withdraw(double amount);
};
