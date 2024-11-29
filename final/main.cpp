#include <iostream>
#include "stockman.h"
#include "stock.h"
#include "account.h"
#include "viewMan.h"
using namespace std;
int main() {
	string name;
	stockman sm = stockman();
	cout << "WELCOME TO THE AMAZING STOCK SIMULATOR!!!!" << endl;
	cout << "WHO WANTS TO BECOME RICH FROM THE STOCK MARKET!!!" << endl;
	cout << "enter name : ";
	cin >> name;
	cout << endl;
	account user(sm, name);
	viewMan x(&user, sm);
	//starts menu
	x.userInterface();
	return 0;
	exit;
}