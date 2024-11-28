#pragma once
using namespace std;
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include "stockman.h"
#include "stock.h"
#include "account.h"

class viewMan
{
private:
	void prices();
	void owned();
	void balence();
	void exit();
	void menu();
	void transaction();
	void passTime();
	void swapAccount();
	stockman& sm;
	account* a;
	account* b;
	vector<account*> accounts;
public:
	viewMan(account* a, stockman& sm);
	void userInterface();



};

