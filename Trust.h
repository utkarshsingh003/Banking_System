
#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Trust :public Account
{
private:
	int limits;
public:
	Trust();
	Trust(string n, int a, string P, double b);
	virtual bool deposit(double amount);
	virtual bool withdraw(double amount);
	virtual void print(ostream& os) const override;
};
