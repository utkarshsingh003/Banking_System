#pragma once
#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include <iostream>
#include <vector>
using namespace std;

//For Savings
void display(vector <Savings>& accounts);
void deposit(vector <Savings>& accounts,double amount);
void withdraw(vector <Savings>& accounts, double amount);

//For Current
void display(vector <Current>& accounts);
void deposit(vector <Current>& accounts,double amount);
void withdraw(vector <Current>& accounts,double amount);

//For Checking
void display(vector <Checking>& accounts);
void deposit(vector <Checking>& accounts,double amount);
void withdraw(vector <Checking>& accounts,double amount);

//For Trust
void display(vector <Trust>& accounts);
void deposit(vector <Trust>& accounts,double amount);
void withdraw(vector <Trust>& accounts,double amount);
