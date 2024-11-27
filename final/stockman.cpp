#include "stockman.h"

stockman::stockman(string account) {
    this->account = account;
}

string stockman::getAccount() {
    return account;
}

int stockman::getBalance() {
    return 1234;
}

int stockman::getStock(string name) {
    return 4321;
}