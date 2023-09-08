// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef MOUSE_H_
#define MOUSE_H_

#include "PeripheralDevice.h"

class Mouse : public PeripheralDevice{
private:
    int dpi;
public:
    Mouse(int,string,string,bool,int);

    // getters and setters

    void setDpi(int);
    int getDpi() const;

    // prints connection text
    void connect(const Computer&) const override;
    // converts item information to string
    operator string() const override;
};
#endif