#include <iostream>
#include "stockman.h"
#include "stock.h"
#include "account.h"
#include "viewMan.h"
int main() {
	//test code no real usage
	std::cout << "test" << std::endl;
	stockman sm = stockman();
	account user(sm, "nitro");
	bool run = true;
	viewMan x(&user, sm);
	x.userInterface();
	return 0;
}