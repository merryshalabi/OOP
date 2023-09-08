// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef PERIPHERALDEVICE_H
#define PERIPHERALDEVICE_H

#include <string>

#include "Item.h"
#include "HWExceptions.h"
#include "Computer.h"
class Computer;

using std::string;

class PeripheralDevice : public Item
{
private:
    string color; // device color
    bool isWireless;
    Computer* connectedComputer; // the computer that the PeripheralDevice is connected to
public:
    // Ctrs/Dtrs
    PeripheralDevice(int, string, string, bool);
    virtual ~PeripheralDevice();

    /*
        Functions
    */

    // connects to computer
    virtual void connect(Computer*) = 0;
    void disconnect();
    // converts item information to string
    virtual operator string() const = 0;

    /*
        Getters and setters
    */

    void setIsWireless(bool);
    bool getIsWireless() const;
    void setColor(const string&);
    string getColor() const;
};
#endif