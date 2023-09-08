// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using std::string;

class Item{
private:
    int price;
    string manufacturer;
    const int id;
    static int nextId; // id of next item created
public:
    // Ctrs/Dtrs

    Item(int,const string&);
    virtual ~Item();

    /*
        Getters and setters
    */

    double getPrice() const;
    void setPrice(int);
    string getManufacturer() const;
    void setManufacturer(const string&);
    int getId() const;

    // Functions

    // converts item information to string
    virtual operator string() const = 0;
};
#endif