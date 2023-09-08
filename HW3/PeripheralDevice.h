// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef PERIPHERALDEVICE_H_
#define PERIPHERALDEVICE_H_

#include <string>
#include "Item.h"
#include "Computer.h"

using std::string;

class PeripheralDevice : public Item{
private:
    string color;
    bool isWireless;
public:
    PeripheralDevice(int, string, string, bool);

    // getters and setters

    void setIsWireless(bool);
    bool getIsWireless() const;
    void setColor(const string&);
    string getColor() const;

    // prints connection text
    virtual void connect(const Computer&) const = 0;
    // converts item information to string
    virtual operator string() const = 0;
};
#endif