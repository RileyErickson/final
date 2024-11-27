#include <iostream>
#include "stockman.h"
int main() {
	std::cout << "test1" << std::endl;
	stockman user("nitro");
	cout << "Account Name: " << user.getAccount() << endl;
	return 0;
}