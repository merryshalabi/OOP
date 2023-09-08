// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef MOUSE_H
#define MOUSE_H

#include <string>

#include "PeripheralDevice.h"

using std::string;

class Mouse : public PeripheralDevice
{
    int dpi;
public:
    Mouse(int,string,string,bool,int);

    /*
        Getters and setters
    */

    void setDpi(int);
    int getDpi() const;

    /*
        Functions
    */

    // prints connection text
    void connect(Computer*) override;
    // converts item information to string
    operator string() const override;
};
#endif