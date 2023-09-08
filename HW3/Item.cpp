// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Item.h"

#include <iostream>
#include <string>
using std::string;

int Item::nextId = 1; // initialize static next_id value

Item::Item(int price, const string& manufacturer) : id(nextId++), price(price), manufacturer(manufacturer) {};

Item::~Item(){
    std::cout << "Throwing away an item" << std::endl;
}

double Item::getPrice() const {
    return this->price;
}
void Item::setPrice(int price) {
     this->price = price;
      }
string Item::getManufacturer() const { 
    return manufacturer;
}
void Item::setManufacturer(const string& manufacturer) {
    this->manufacturer = manufacturer;
}
int Item::getId() const { 
    return id;
}

Item::operator string() const{
    return ("id "+ std::to_string(this->id) +": "+ this->manufacturer +" "+ std::to_string(this->price)+ "$");
}
