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
	stockman& sm;
	account& a;
public:
	viewMan(account& a, stockman& sm);
	void userInterface();



};

