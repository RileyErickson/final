#include "viewMan.h"



	viewMan::viewMan(account* a, stockman& sm) : sm(sm) {	
		//which ever account we are starting with
		this->a = a;
		accounts.push_back(a);
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
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			counter = 0;
		}
	}
	userInterface();
}

void viewMan::owned() {
	int counter = 0;
	for (stock& s : sm.getStocks()) {
		counter++;
		cout << s.getName() << ": " << a->getStockAmount(s.getName());
		if (counter != 3) {
			cout << " | ";
		}
		else {
			cout << endl;
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			counter = 0;
		}
	}
	userInterface();
}

void viewMan::balence() {
	
	cout << " Balence: " << a->getBalance() << endl;
	//shows how much money has been made by an account
	cout << " Profits: " << (a->getBalance() - a->getDeposited()) + a->getWithdrew() << endl;
	userInterface();
}
//exits program since it does not call userInterface to return to main menu
void viewMan::exit() {
	cout << "Have a Great Day!=)" << endl;
}
void viewMan::passTime() {
	sm.updateAllStocks();
	cout << "Check those New Prices!" << endl;
	userInterface();
}
void viewMan::menu() {

	cout << a->getName() <<"'s account" << endl;
	cout << "make a selection (type 0-5 to a make choice)" << endl;
	cout << "1. make a transaction (buy/sell)" << endl;
	cout << "2. check your balence " << endl;
	cout << "3. check stock prices" << endl;
	cout << "4. view owned stocks" << endl;
	cout << "5. pass time " << endl;
	cout << "6. change user " << endl;
	cout << "7. make deposit/withdraw" << endl;
	cout << "0. exit" << endl;
}
void viewMan::transaction() {

}
void viewMan::depositWithdraw() {
	int choice = -1;
	string input = "";
	//takes users input and passes it off to the correct method
	cout << "type (W) to withdraw and (D) to deposit or (E) to exit this menu" << endl;
	cin >> input;
	if ((input == "d") || (input == "D")) {
		cout << "deposit" << endl;
	}
	if ((input == "w") || (input == "W")) {
		cout << " withdrew" << endl;
	}
	if ((input == "e") || (input == "E")) {
		userInterface();
	}
	depositWithdraw();

}


void viewMan::userInterface() {
	int choice = -1;
	string input = "";
	//takes users input and passes it off to the correct method
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
	case 6:
		swapAccount();
		break;
	case 7:
		depositWithdraw();
	case 0:
		exit();
		break;
	default:
		userInterface();
		break;
	}


}
void viewMan::swapAccount() {
	string aName;
	
	cout << "give the name of the account to log in as, or the name of a new account to make" << endl;
	for (account* a : accounts) {
		cout << a->getName() << endl;
	}
	cin >> aName;
	bool found = false;
	for (account* acc : accounts) {
		if (acc->getName() == aName) {
			a = acc;
			found = true;
		}
	}
	a = new account(sm, aName);
	accounts.push_back(a);
	userInterface();
}