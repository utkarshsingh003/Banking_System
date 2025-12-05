#pragma once
#include <iostream>
#include <string>
using namespace std;

class Printable
{
	friend ostream& operator<<(ostream& os, const Printable& rhs)
	{
		rhs.print(os);
		return os;
	}
	friend istream& operator>>(istream& is, Printable& rhs)
	{
		rhs.input(is);
		return is;
	}
public:
	virtual void print(ostream& os) const = 0;
	virtual void input(istream& is) = 0;
};

class Account :public Printable
{
protected:
	string name;
	int age;
	string PAN;
	double balance;
	long int Acc_no;

public:
	Account();
	Account(string n, int a, string P, double b);
	virtual bool deposit(double amount);
	virtual bool withdraw(double amount);
	virtual void print(ostream& os) const override;
	virtual void input(istream& is) override;
};
