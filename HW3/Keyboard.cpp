// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Keyboard.h"

#include <iostream>
#include <string>
using std::string;

Keyboard::Keyboard(int price, string manufacturer, string color, bool isWireless, int keys) :
                    PeripheralDevice(price,manufacturer,color,isWireless), keys(keys) {};

void Keyboard::setNumOfKeys(int keys) {
    this->keys = keys;
}
int Keyboard::getNumOfKeys() const {
    return this->keys;
}

void Keyboard::connect(const Computer& pc) const {
    std::cout << "Connecting a keyboard" << std::endl;
    PeripheralDevice::connect(pc);
}

Keyboard::operator string() const {
    return ( PeripheralDevice::operator string() +", Keyboard with "+ std::to_string(this->keys) +" keys" );
}