#include "account.h"

account::account(stockman& stockManager, string name) : sm(stockManager){
    this->name = name;
    balance = 5000;
    for (stock s : stockManager.getStocks()) {
        owned_stocks.emplace_back(s.getName(), 0);
    }
    withdrew = 0;
    deposited = balance;
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
string account::getName() {
    return name;
}
double account::getWithdrew() {
    return withdrew;
}
double account::getDeposited() {
    return deposited;
}
void account::addDeposited(double x) {
    deposited = deposited + x;

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