#include "account.h"

account::account(stockman& stockManager, string name) : sm(stockManager){
    this->name = name;
    balance = 5000;
    //loads all the stocks created
    for (stock s : stockManager.getStocks()) {
        owned_stocks.emplace_back(s.getName(), 0);
    }
    withdrew = 0;
    deposited = balance;
    spent = 0.0;
    ren = 0;
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
//thought I would need, not used for application
void account::addDeposited(double x) {
    deposited = deposited + x;

}
//thought I would need, not used for application
void account::addWithdraw(double x) {
    withdrew = withdrew + x;

}
void account::setBalance(double update) {
    balance = update;
}
double account::getRen() {
    return ren;
}
void account::addRen(double update) {
    ren = ren + update;
}
double account::getSpent() {
    return spent;
}
void account::addSpent(double update) {
    spent = spent + update;
}
int account::purchaseStock(string stockName, int quantity) {
    for (tuple<string, int>& s : owned_stocks) {
        if (get<0>(s) == stockName) {
            get<1>(s) = get<1>(s) + quantity;
            return 0;
        }
    }
    return 1;
}

int account::sellStock(string stockName, int quantity) {
    for (tuple<string, int>& s : owned_stocks) {
        if (get<0>(s) == stockName) {
            get<1>(s) = get<1>(s) - quantity;
            return 0;
        }
    }
    return 1;
}