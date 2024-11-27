#include <iostream>
#include "stockman.h"
#include "stock.h"
int main() {
	//test code no real usage
	std::cout << "test2" << std::endl;
	stockman sm("nitro");
	stock  x("nitro", 4000.0);
	cout << "Account Name: " << sm.getAccount() << " " << x.getName() << " " << x.getPrice() << endl;

	
	sm.updateAllStocks();
	for (stock s : sm.getStocks()) {
		std::cout << "Stock Name: " << s.getName()
			<< ", Price: " << s.getPrice()
			<< std::endl;
	}

	return 0;
}