// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef WEBCAM_H
#define WEBCAM_H

#include <string>

#include "PeripheralDevice.h"

using std::string;

class Webcam : public PeripheralDevice
{
private:
    string resolution;
    
public:
    // Ctr
    Webcam(int,const string&,const string&,bool,const string&);

    /*
        Functions
    */

    // prints connection text
    void connect(Computer*) override;
    // converts item information to string
    operator string() const override;

    /*
        Getters and setters
    */

    string getResolution() const;
    void setResolution(const string&);
};

#endif
