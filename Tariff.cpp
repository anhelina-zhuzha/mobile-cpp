#include "Tariff.h"
#include <iostream>

Tariff::Tariff(std::string name, double price) : name(name) {
    this->name = name;
    this->price = price;
}

std::string Tariff::getName(){
    return name;
}

double Tariff::getPrice() const {
    return price;
}
