#include "Account.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

Account::Account()
	:name{ "None" }, age{ 0 }, PAN{ "None" }, balance{ 0.0 }, Acc_no{ 000000 }
{

}
Account::Account(string n, int a, string P, double b)
	:name{ n }, age{ a }, PAN{ P }, balance{ b }
{
    srand(time(0));
    Acc_no = rand() % 100000 + 1;
}
bool Account::deposit(double amount)
{
	if (amount <= 0)
		return false;

	else
	{
		balance += amount;
		return true;
	}
}
bool Account::withdraw(double amount)
{
	if (amount > balance)
		return false;

	else
	{
		balance -= amount;
		return true;
	}
}
