#include "stockman.h"

stockman::stockman() {
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
    stocks.push_back(stock("wat", 334.29));
    stocks.push_back(stock("zat", 334.29));

}

stock& stockman::getStock(string name) {
    for (stock& s : stocks) {
        if (s.getName() == name) {
            return s;
        }
    }
    
}
 std::vector<stock>& stockman::getStocks()  {
    return stocks;
}
void stockman::updateAllStocks() {
     for (stock& s : stocks) {
             s.updateStock();
     }
 }
