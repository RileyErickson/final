#include "account.h"
account::account(stockman& stockManager) {
    for (stock s : stockManager.getStocks()) {

    }
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