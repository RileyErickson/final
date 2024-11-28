#pragma once
#include <string>
#include <vector>
#include <tuple>
#include "stockman.h"
using namespace std;
class account
{
private:
    double balance;
    stockman sm;
    vector<tuple<string, int>> owned_stocks;
public:
    account(stockman& stockManager);
    double getBalance() ;
    int getStockAmount(string name);
    void setBalance(double newBalance);
    int purchaseStock(string stockName, int quantity);
    int sellStock( string stockName, int quantity);
};


