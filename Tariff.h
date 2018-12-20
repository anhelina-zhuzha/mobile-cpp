#ifndef PATTERNS_TARIFF_H
#define PATTERNS_TARIFF_H

#include <iostream>
#include <cmath>

class Tariff {

private:
    std::string name;

    double price;

public:
    std::string getName();

    double getPrice() const;

public:
    Tariff(std::string name, double price);
};


#endif //PATTERNS_TARIFF_H
