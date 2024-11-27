#include "stockman.h"

stockman::stockman(string account) {
    this->account = account;
    balence = 5000.0;
    stocks.push_back(stock("tat", 120.22));
    stocks.push_back(stock("nat", 133.53));
    stocks.push_back(stock("cat", 49.26));
    stocks.push_back(stock("bat", 120.43));
    stocks.push_back(stock("fat", 210.32));
    stocks.push_back(stock("rat", 385.65));
    stocks.push_back(stock("mat", 320.84));
    stocks.push_back(stock("pat", 524.32));
    stocks.push_back(stock("sat", 145.23));
    stocks.push_back(stock("vat", 334.29));
}

string stockman::getAccount() {
    return account;
}

int stockman::getBalance() {
    return 1234;
}

int stockman::getStock(string name) {
    return 4321;
}
 std::vector<stock>& stockman::getStocks()  {
    return stocks;
}
void stockman::updateAllStocks() {
     for (stock& s : stocks) {
         s.updateStock();  
     }
 }
