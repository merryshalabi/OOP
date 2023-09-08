// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef BRANCH_H
#define BRANCH_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "HWExceptions.h"
#include "Item.h"

using std::string;
using std::vector;

class Branch
{
private:
    vector<Item*> catalog; // Branch items
    const int capacity; // Max items
    string location; // Branch location
public:
    /*
        Ctrs / Dtrs
    */
    Branch();
    Branch(const string&, int);
    Branch(const Branch& other);
    ~Branch();

    /*
        Functions
    */

    // Adds item to catalog array
    void addItem(Item*);
    // Deletes item from catalog with given id
    Item* deleteItem(int);

    int calculateValue() const; // returns branch value

    // Gets 2 item pointers, returns true if first item price is less than second item price
    static bool compareByPrice(Item*,Item*);
    // Gets 2 item pointers, returns true if first item id is less than second item id
    static bool compareById(Item*,Item*);

    /*
        Printing functions
    */

    void printBranchInfo() const;
    // gets Item pointer vector and prints items with their string operator
    void printItemVector(vector<Item*> vec) const;

    void print_catalog_by_price() const;
    void print_catalog_by_id() const;

    /* 
        Getters and setters
    */

    vector<Item*>& getCatalog(void);
    int getCapacity() const;
    string getLocation() const;
    void setLocation(const string&);

    template <class T>
    T* retrieveFinest(T* item) const
    {
        T* maxPriceItem = NULL;
        T* temp;

        for(Item* vecItem : this->catalog) // go over catalog
        {
            temp = dynamic_cast<T*>(vecItem);
            
            if(temp != NULL) // cast was succsessful, vecItem is a T*
            {
                if(maxPriceItem == NULL) maxPriceItem = temp; // first item is max

                else
                {
                    if(maxPriceItem->getPrice() < temp->getPrice()){ // found new max
                        maxPriceItem = temp;
                    }
                }
            }
        }
        if(maxPriceItem == NULL) throw NoneExistingItemTypeError(); // did not find a T*

        return maxPriceItem;
    }
};
#endif
