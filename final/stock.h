#pragma once

#include <string>
using namespace std;
class stock {
private:
    std::string name;
    double price;

public:
    stock(string n, double p);

    string getName();
    void setName(string newName);

    double getPrice();
    void setPrice(double newPrice);

    void updateStock();
};



