// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Mouse.h"

Mouse::Mouse(int price, string manufacturer, string color, bool isWireless, int dpi) :
    PeripheralDevice(price,manufacturer,color,isWireless), dpi(dpi) {};

void Mouse::setDpi(int dpi)
{
    this->dpi = dpi;
}
int Mouse::getDpi() const
{
    return this->dpi;
}

void Mouse::connect(Computer* pc)
{
    std::cout << "Connecting a mouse" << std::endl;
    PeripheralDevice::connect(pc);
}

Mouse::operator string() const
{
    return ( PeripheralDevice::operator string() +", Mouse with dpi : "+ std::to_string(this->dpi));
}
