#include "stock.h"
#include <iostream>

stock::stock(string n, double p) {
    price = p;
    name = n;
}
std::string stock::getName() {
    return name;
}

void stock::setName(string name) {
    this->name = name;
}

double stock::getPrice() {
    return price;
}

void stock::setPrice(double price) {
    this->price = price;
}

void stock::updateStock() {
    int increase = rand() % 3;
    //change price from 0-30%
    double percentage = rand() % 15 / 100.0;   
    // 1/3 chance do nothing, increase, or decrease
    if (increase == 1) {
        percentage = 1 + percentage;
    }
    else if (increase == 2) {
        percentage = 1 - percentage;
    }
    else { 
        percentage = 1; 
    }
        //once percentage is calculated the new price is calculated.
        price = price * percentage;
        price = static_cast<int>(price * 100) / 100.0;
 
}
