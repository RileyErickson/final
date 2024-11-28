#pragma once
#include <string>
#include "stockman.h"
using namespace std;
class account
{
private:
    double balance;
    vector<tuple<string, int>> owned_stocks;
public:
    account(stockman& stockManager);
    double getBalance() ;
    void setBalance(double newBalance);
    int purchaseStock(string stockName, int quantity);
    int sellStock( string stockName, int quantity);
};


