// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "PeripheralDevice.h"

PeripheralDevice::PeripheralDevice(int price, string manufacturer, string color, bool isWireless) : 
    Item(price,manufacturer), color(color), isWireless(isWireless)
    {
        this->connectedComputer = NULL;
    };

PeripheralDevice::~PeripheralDevice()
{
    disconnect();
}


void PeripheralDevice::connect(Computer* pc)
{
	if(this->connectedComputer == pc) return; // already connected to pc
    
    if(this->connectedComputer != NULL) throw ConnectError(); // already connected to a Computer

    std::cout << string(*this) << " is Connecting to computer: " << string(*pc) << std::endl;

    this->connectedComputer = pc;
    
    try{
        pc->connectDevice(this);
    }
    catch (std::exception& e)
	{
		this->connectedComputer = NULL;
        throw ConnectError();
	}
}
void PeripheralDevice::disconnect()
{
    if(this->connectedComputer != NULL)
    {
        this->connectedComputer->disconnectDevice(this->getId());
        this->connectedComputer = NULL;
    }
}
PeripheralDevice::operator string() const{
    string wire = this->isWireless ? "Wireless" : "Wired";
    return(Item::operator string() +", "+ wire +", "+ this->color);
}

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
