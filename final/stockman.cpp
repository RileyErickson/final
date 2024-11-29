#include "stockman.h"

stockman::stockman() {
    addStock(stock("tat", 120.22));
    addStock(stock("nat", 133.53));
    addStock(stock("cat", 49.26));
    addStock(stock("bat", 120.43));
    addStock(stock("fat", 210.32));
    addStock(stock("rat", 385.65));
    addStock(stock("mat", 320.84));
    addStock(stock("pat", 524.32));
    addStock(stock("sat", 145.23));
    addStock(stock("vat", 334.29));
    addStock(stock("wat", 334.29));
    addStock(stock("zat", 334.29));

}
 void stockman::addStock(stock s) {
    stocks.push_back(s);
}
stock& stockman::getStock(string name) {
    for (stock& s : stocks) {
        if (s.getName() == name) {
            return s;
        }
    }
    
}
//returns all stocks vs getstock which returns only requested stock
 std::vector<stock>& stockman::getStocks()  {
    return stocks;
}
void stockman::updateAllStocks() {
     for (stock& s : stocks) {
             s.updateStock();
     }
 }
