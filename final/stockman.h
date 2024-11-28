#pragma once
#ifndef stockman_H
#define stockman_H
#include <string>
#include "stock.h"
#include <vector>
using namespace std;
class stockman {
public:
	stockman();
	int getStock(string name);
	vector<stock>& getStocks();
	void updateAllStocks();
private:
	vector<stock> stocks;
};
#endif
