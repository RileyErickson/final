#include "account.h"
account::account(stockman& stockManager) {
    sm = stockManager;
    for (stock s : stockManager.getStocks()) {
        owned_stocks.emplace_back(s.getName(), 0);
    }
}
int account::getStockAmount(string name) {
    for (tuple<string, int> s : owned_stocks) {
        if (get<0>(s) == name) {
            return get<1>(s);
        }
    }
    return -1;
}
double account::getBalance()  {
    return balance;
}

void account::setBalance(double update) {
    balance = update;
}

int account::purchaseStock(string stockName, int quantity) {
    return 1;
}

int account::sellStock(string stockName, int quantity) {
    return 1;
}