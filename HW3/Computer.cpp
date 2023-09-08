// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Computer.h"

#include <string>
using std::string;

Computer::Computer(int price, string manufacturer, string cpu, bool isLaptop) : Item(price,manufacturer), cpu(cpu), isLaptop(isLaptop) {};

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

Computer::operator string() const{
    string pc = this->isLaptop ? "Laptop" : "Desktop";
    return(Item::operator string() +", "+ pc +", "+ this->cpu);
}