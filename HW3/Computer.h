// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef COMPUTER_H_
#define COMPUTER_H_

#include <string>
#include "Item.h"

using std::string;

class Computer : public Item{
private:
    string cpu;
    bool isLaptop;
public:
    Computer(int,string,string,bool);

    // getters and setters

    string getCpu() const;
    void setCpu(const string&);
    bool getIsLaptop() const;
    void setIsLaptop(bool);

    // converts item information to string
    operator string() const override;
};
#endif