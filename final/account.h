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
    stockman& sm;
    vector<tuple<string, int>> owned_stocks;
    string name;
    double withdrew;
    double deposited;
public:
    
    account(stockman& stockManager, string n);
    double getBalance() ;
    string getName();
    int getStockAmount(string name);
    void setBalance(double newBalance);
    int purchaseStock(string stockName, int quantity);
    int sellStock( string stockName, int quantity);
    double getWithdrew();
    void addDeposited(double x);
    void addWithdraw(double x);
    double getDeposited();
};


