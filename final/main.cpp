#include <iostream>
#include "stockman.h"
#include "stock.h"
#include "account.h"
#include "viewMan.h"
using namespace std;
int main() {
	string name;
	//stock manager holds all the stocks for just buying and selling accounts hold their own 
	//record of their stocks.
	stockman sm = stockman();
	//Start message
	cout << "WELCOME TO THE AMAZING STOCK SIMULATOR!!!!" << endl;
	cout << "WHO WANTS TO BECOME RICH FROM THE STOCK MARKET!!!" << endl;
	cout << "enter name : ";
	cin >> name;
	cout << endl;
	//makes first user and the view manager, view manager handles each menu and swapping between them
	account user(sm, name);
	viewMan x(&user, sm);
	//starts menu
	x.userInterface();
	return 0;
	exit;
}