#pragma once
using namespace std;
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <cstdlib>
#include "stockman.h"
#include "stock.h"
#include "account.h"

class viewMan
{
private:
	void prices();
	void owned();
	void balence();
	void quit();
	void menu();
	void transaction();
	void passTime();
	void swapAccount();
	void depositWithdraw();
	stockman& stockManager;
	account* activeUser;
	account* b;
	vector<account*> accounts;
public:
	viewMan(account* a, stockman& sm);
	void userInterface();



};

