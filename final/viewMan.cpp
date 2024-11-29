#include "viewMan.h"



	viewMan::viewMan(account* a, stockman& sm) : sm(sm) {	
		//which ever account we are starting with
		this->a = a;
		accounts.push_back(a);
	}
//prices/owned calls nothing at the end so other methods can use them for display purposes without them
//automaticly going to a new menu
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
	//userInterface();
}

void viewMan::owned() {
	int counter = 0;
	for (stock& s : sm.getStocks()) {
		counter++;
		cout << s.getName() << ": " << a->getStockAmount(s.getName()) <<" $: " << sm.getStock(s.getName()).getPrice() * a->getStockAmount(s.getName());
		if (counter != 3) {
			cout << " | ";
		}
		else {
			cout << endl;
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			counter = 0;
		}
	}
	//userInterface();
}

void viewMan::balence() {
	
	cout << " Balence: " << a->getBalance() << endl;
	//shows how much money has been made by an account
	cout << " Profits: " << (a->getRen() - a->getSpent()) << endl;
	userInterface();
}
//exits program since it does not call userInterface to return to main menu
void viewMan::exit() {
	cout << "Have a Great Day!=)" << endl;
}
void viewMan::passTime() {
	sm.updateAllStocks();
	cout << "Check out those New Prices!" << endl;
	prices();
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
	string input = "";
	int amount = 0;
	double price = 0;
	bool validStock = false;
	cout << "type (S) to sell and (B) to buy or (E) to exit this menu" << endl;
	cin >> input;
	if ((input == "b") || (input == "B")) {
		cout << "which stock would you like to buy?" << endl;
		prices();
		cin.clear();
		cin >> input;
		//checks stock selection
		for (stock& s : sm.getStocks()) {
			if (s.getName() == input) {
				validStock = true;
				price = s.getPrice();
			}
		}
		if (!validStock) {
			cout << "sorry I don't see a stock named: " << input << endl;
			transaction();
		}
		//checks amount
		cout << "how much would you like to buy?" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> amount;
		//validates user input
		while (cin.fail()|| amount <=0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "thats not right, try again" << endl;
			cin >> amount;
		}
		if (!(price * amount <= a->getBalance())) {
			cout << "am sorry you can't afford that much" << endl;
			transaction();
		}
		a->purchaseStock(input, amount);
		a->setBalance(a->getBalance() - amount*price);
		a->addSpent(amount*price);
		cout << "Congrats you now own " << amount << " of " << input << endl;

	}
	//handles selling a copy of the buying process but with the end step changed.
	else if ((input == "s") || (input == "S")) {
		cout << "which stock would you like to sell?" << endl;
		prices();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		owned();
		cin.clear();
		cin >> input;
		//checks stock selection
		for (stock& s : sm.getStocks()) {
			if (s.getName() == input) {
				validStock = true;
				price = s.getPrice();
			}
		}
		if (!validStock) {
			cout << "sorry I don't see a stock named: " << input << endl;
			transaction();
		}
		//checks amount
		cout << "how much would you like to sell?" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> amount;
		//validates user input
		while (cin.fail() || amount <= 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "thats not right, try again" << endl;
			cin >> amount;
		}
		//stops selling more then you have
		if ((amount > a->getStockAmount(input))) {
			cout << "am sorry you can't sell more then you have" << endl;
			transaction();
		}
		a->sellStock(input, amount);
		a->addRen(amount*price);
		a->setBalance(a->getBalance() + amount * price);
		cout << "Congrats you sold " << amount << " of " << input << " for "<< amount*price << endl;
	} else if ((input == "e") || (input == "E")) {
		userInterface();
	}
	transaction();
}
void viewMan::depositWithdraw() {
	double amount = 0;
	string input = "";
	//takes users input and passes it off to the correct method
	cout << "type (W) to withdraw and (D) to deposit or (E) to exit this menu" << endl;
	cin >> input;
	if ((input == "d") || (input == "D")) {
		cout << " how much would you like to deposit? example (23.43)" << endl;
		cin >> amount;
		//validates user input
		while (cin.fail() || amount < 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "thats not right try again type it like 0.00" << endl;
			cin >> amount;
		}
		//prevents 23.3242343225 inputs
		amount = static_cast<int>(amount * 100) / 100.0;
		a->setBalance(a->getBalance() + amount);
		a->addDeposited(amount);
		userInterface();
	}
	if ((input == "w") || (input == "W")) {
		bool validAmount = false;
		//validates user input
		while (!validAmount) {
			cout << " how much would you like to withdraw? example (23.43)" << endl;
			cin >> amount;
			while (cin.fail() || amount < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "thats not right try again type it like 0.00" << endl;
				cin >> amount;
			}
			//checks if its less then or equal to balance before allowing withdraw
			if (amount <= a->getBalance()) {
				validAmount = true;
			}
			else {
				cout << "thats more then your balence of " << a->getBalance() << endl;
			}
		}
		a->setBalance(a->getBalance() - amount);
		a->addWithdraw(amount);
		
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
		userInterface();
		break;
	case 4:
		owned();
		userInterface();
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
	if (!found) {
		a = new account(sm, aName);
		accounts.push_back(a);
	}
	userInterface();
}