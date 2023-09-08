// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef BRANCH_H_
#define BRANCH_H_

#include <string>
#include "Item.h"
#define STORE_SIZE 10

using std::string;

class Branch{
private:
    Item* catalog[STORE_SIZE];
    int items = 0; // item count
    int next_index = 0; // index for next item to be added
    string location;
public:
    Branch(const string&);
    ~Branch();

    // Adds item to catalog array, replaces oldest item if full
    void addItem(Item*);

    // getters and setters

    int getItems() const;
    Item** getCatalog(int&);
    string getLocation() const;
    void setLocation(const string&);
};
#endif