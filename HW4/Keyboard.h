// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "PeripheralDevice.h"

class Keyboard : public PeripheralDevice
{
    int keys;
public:
    Keyboard(int,string,string,bool,int);

    /*
        Getters and setters
    */

    void setNumOfKeys(int);
    int getNumOfKeys() const;

    /*
        Functions
    */
    // connects to computer
    void connect(Computer*) override;
    // converts item information to string
    operator string() const override;
};
#endif