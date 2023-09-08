// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Computer.h"

Computer::Computer(int price, string manufacturer, string cpu, bool isLaptop, int ports) :
    Item(price,manufacturer), cpu(cpu), isLaptop(isLaptop), ports(ports) {};


void Computer::connectDevice(const PeripheralDevice* device)
{
    if(this->connectedDevices.size() >= this->ports) throw ConnectError(); // cant connect more devices

    for(const PeripheralDevice* vecDevice : this->connectedDevices) // for each device in computer
    {
        if(vecDevice->getId() == device->getId()) throw ConnectError(); // if device is already in computer
    }

    this->connectedDevices.push_back(device);
}
void Computer::disconnectDevice(int id)
{
    // go over devices and find device with given id
    for(int i=0; i < this->connectedDevices.size(); i++)
    {
        if(this->connectedDevices[i]->getId() == id)
        {
            this->connectedDevices.erase(this->connectedDevices.begin()+i); // delete device pointer from vector
        }
    }
}

void Computer::print_connected() const
{
    std::cout << "There are "+std::to_string(this->connectedDevices.size())+" connection to " + string(*this) << std::endl;
    for(const PeripheralDevice* device : this->connectedDevices)
    {
        std::cout << string(*device) << std::endl;
    }
}

Computer::operator string() const{
    string pc = this->isLaptop ? "Laptop" : "Desktop";
    return(Item::operator string() +", "+ pc +", "+ this->cpu);
}

string Computer::getCpu() const {
    return this->cpu;
}
void Computer::setCpu(const string& cpu) {
    this->cpu = cpu;
}
bool Computer::getIsLaptop() const{
    return this->isLaptop;
}
void Computer::setIsLaptop(bool isLaptop){
    this->isLaptop = isLaptop;
}
int Computer::getPorts() const
{
    return this->ports;
}
vector<const PeripheralDevice*> Computer::getConnectedDevices(void)
{
    return this->connectedDevices;
}
