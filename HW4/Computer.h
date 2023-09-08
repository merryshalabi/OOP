// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <iostream>
#include <vector>

#include "Item.h"
#include "PeripheralDevice.h"
class PeripheralDevice;

using std::string;
using std::vector;

class Computer : public Item{
private:
    string cpu;
    bool isLaptop;
    const int ports;
    vector<const PeripheralDevice*> connectedDevices;
public:
    // Ctr
    Computer(int,string,string,bool,int);

    /*
        Functions
    */

    void connectDevice(const PeripheralDevice*); // connects device to computer
    void disconnectDevice(int); // gets id, removes device with given id

    void print_connected() const;

    // converts item information to string
    operator string() const override;

    /*
        Getters and setters
    */

    string getCpu() const;
    void setCpu(const string&);
    bool getIsLaptop() const;
    void setIsLaptop(bool);
    int getPorts() const;
    vector<const PeripheralDevice*> getConnectedDevices(void);
};
#endif