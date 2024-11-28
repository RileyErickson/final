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
    void setName(string name);

    double getPrice();
    void setPrice(double price);

    void updateStock();
};



