#include "viewMan.h"



viewMan::viewMan(account& a, stockman& sm) : a(a), sm(sm) {	
}
//end of each piece it re enters the main directory by calling userInterface
void viewMan::prices() {
	int counter = 0;
	for (stock& s : sm.getStocks()) {
		counter++;
		cout << s.getName() << ": " << s.getPrice();
		if (counter != 3) {
			cout << " | ";
		}
		else {
			cout << endl;
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
			counter = 0;
		}
	}
	userInterface();
}

void viewMan::owned() {

	userInterface();
}

void viewMan::balence() {

	userInterface();
}

void viewMan::exit() {
	cout << "Have a Great Day!=)" << endl;
}
void viewMan::passTime() {
	sm.updateAllStocks();
	cout << "Check those New Prices!" << endl;
	userInterface();
}
void viewMan::menu() {
	cout << "1. make a transaction (buy/sell)" << endl;
	cout << "2. check your balence " << endl;
	cout << "3. check stock prices" << endl;
	cout << "4. view owned stocks" << endl;
	cout << "5. view owned stocks" << endl;
	cout << "0. exit" << endl;
}
void viewMan::transaction() {

userInterface();
}

void viewMan::userInterface() {
	int choice = -1;
	string input = "";
	//takes users input and passes it off to the correct method
	cout << "make a selection (type 0-5 to a make choice)"<<endl;
	menu();
	while (choice == -1) {
		cin >> input;
		try { choice = stoi(input); }
		catch (...) { cout << "try again" << endl;}
	}
	//handles breaking out into each specific piece 
 	switch (choice) {
	case 1 :
		transaction();
		break;
	case 2 : 
		balence();
		break;
	case 3:
		prices();
		break;
	case 4:
		owned();
		break;
	case 5:
		passTime();
		break;
	case 0:
		exit();
		break;
	default:
		userInterface();
		break;
	}

	cout << "test worked" << endl;

}