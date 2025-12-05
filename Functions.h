#pragma once
#include "Account.h"
#include "Savings.h"
#include "Current.h"
#include "Checking.h"
#include "Trust.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//For Savings
void display(unique_ptr<vector<shared_ptr<Account>>>& accounts);
void deposit(unique_ptr<vector<shared_ptr<Account>>>& accounts);
void withdraw(unique_ptr<vector<shared_ptr<Account>>>& accounts);
void history(unique_ptr<vector<shared_ptr<Account>>>& accounts);

