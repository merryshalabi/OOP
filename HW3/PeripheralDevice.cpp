// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "PeripheralDevice.h"

#include <string>
#include <iostream>
using std::string;

PeripheralDevice::PeripheralDevice(int price, string manufacturer, string color, bool isWireless) : 
                                    Item(price,manufacturer), color(color), isWireless(isWireless) {};


void PeripheralDevice::setIsWireless(bool isWireless) {
    this->isWireless = isWireless;
}
bool PeripheralDevice::getIsWireless() const {
    return this->isWireless;
}
void PeripheralDevice::setColor(const string& color) {
    this->color = color;
}
string PeripheralDevice::getColor() const {
    return this->color;
}

void PeripheralDevice::connect(const Computer& pc) const {
	
	std::cout << std::string(*this) << " is Connecting to computer: " << std::string(pc) << std::endl;
}

PeripheralDevice::operator string() const{
    string wire = this->isWireless ? "Wireless" : "Wired";
    return(Item::operator string() +", "+ wire +", "+ this->color);
}