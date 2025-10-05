#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	string name;
	int age;
	string PAN;
	double balance;
	long int Acc_no;

public:
	Account();
	Account(string n, int a, string P, double b);
	bool deposit(double amount);
	bool withdraw(double amount);

};
