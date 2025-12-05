#pragma once
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Current :public Account
{
private:
	int limits;

public:
	Current();
	Current(string n, int a, string P, double b);
	virtual bool deposit(double amount);
	virtual bool withdraw(double amount);
	virtual void print(ostream& os) const override;
};
