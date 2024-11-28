#include "viewMan.h"



viewMan::viewMan(account& a, stockman& sm) : a(a), sm(sm) {	
}

void viewMan::prices() {
}

void viewMan::owned() {
}

void viewMan::balence() {
}

void viewMan::exit() {
}

void viewMan::menu() {
}

void viewMan::userInterface() {
	int choice = -1;
	string input = "";
	cout << "make a selection (type 1-X to make choice)"<<endl;
	while (choice == -1) {
		cin >> input;
		try { choice = stoi(input); }
		catch (...) { cout << "try again" << endl; }
	}
	cout << "test worked" << endl;

}