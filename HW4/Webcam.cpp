// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Webcam.h"

Webcam::Webcam(int price, const string& manufacturer, const string& color, bool isWireless, const string& resolution) :
    PeripheralDevice(price,manufacturer,color,isWireless), resolution(resolution) {};

void Webcam::connect(Computer* pc)
{
    std::cout << "Connecting a webcam" << std::endl;
    PeripheralDevice::connect(pc);
}
Webcam::operator string() const
{
    return (PeripheralDevice::operator string() +", Webcam with "+ this->resolution +" resolution");
}

void Webcam::setResolution(const string& resolution)
{
    this->resolution = resolution;
}
string Webcam::getResolution() const
{
    return this->resolution;
}
