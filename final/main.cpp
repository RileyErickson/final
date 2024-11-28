#include <iostream>
#include "stockman.h"
#include "stock.h"
#include "account.h"
int main() {
	//test code no real usage
	std::cout << "test2" << std::endl;
	stockman sm = stockman();
	stock  x("nitro", 4000.0);
	account a(sm);
	sm.updateAllStocks();
	string name;
	while (true){
		cin >> name;
		std::cout << a.getStockAmount(name) << std::endl;
	}
	return 0;
}