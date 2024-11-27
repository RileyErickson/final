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
    std::cout << "test" << std::endl;
}
