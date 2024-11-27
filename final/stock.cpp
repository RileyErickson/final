#include "stock.h"
#include <iostream>

stock::stock(string n, double p) {
    price = p;
    name = n;
}
std::string stock::getName() {
    return name;
}

void stock::setName(string newName) {
    name = newName;
}

double stock::getPrice() {
    return price;
}

void stock::setPrice(double newPrice) {
    price = newPrice;
}

void stock::updateStock() {
    bool increase = rand() % 3;
    //change price from 0-15%
    double percentage = rand() % 16 / 100.0;
    std::cout << percentage << "%" << endl;
    percentage = static_cast<int>(percentage * 100) / 100.0;
   
    // 1/3 chance do nothing, increase, or decrease
    int change = 0;
    if (increase == 1) {
        change = 1 + percentage;
    }
    else if (increase == 2) {
        change = 1 - percentage;
    }

    if (change != 0) {
        price = price * change;
        price = static_cast<int>(price * 100) / 100.0;
    }

    std::cout << "test" << std::endl;
}
