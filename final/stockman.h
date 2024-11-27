#pragma once
#ifndef stockman_H
#define stockman_H
#include <string>

using namespace std;
class stockman {
public:
	stockman(string  accountname);
	string getAccount();
	int getBalance();
	int getStock(string name);
private:
	string account;
};
#endif
