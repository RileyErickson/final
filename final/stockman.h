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
	stock& getStock(string name);
	vector<stock>& getStocks();
	void updateAllStocks();
	void addStock(stock s);
private:
	vector<stock> stocks;
};
#endif
