#pragma once
#ifndef stockman_H
#define stockman_H
#include <string>
#include "stock.h"
#include <vector>
using namespace std;
class stockman {
public:
	stockman(string  accountname);
	string getAccount();
	int getBalance();
	int getStock(string name);
	vector<stock>& getStocks();
	void updateAllStocks();
private:
	string account;
	vector<stock> stocks;
	double balence;

};
#endif
