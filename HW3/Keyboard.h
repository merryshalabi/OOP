// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include "PeripheralDevice.h"

class Keyboard : public PeripheralDevice{
private:
    int keys;
public:
    Keyboard(int,string,string,bool,int);

    void setNumOfKeys(int);
    int getNumOfKeys() const;

    // prints connection text
    void connect(const Computer&) const override;
    // converts item information to string
    operator string() const override;
};
#endif