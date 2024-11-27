#include <iostream>
#include "stockman.h"
#include "stock.h"
int main() {
	std::cout << "test2" << std::endl;
	stockman user("nitro");
	stock  s("nitro", 4000.0);
	cout << "Account Name: " << user.getAccount() << " " << s.getName() << " " << s.getPrice() << endl;
	return 0;
}