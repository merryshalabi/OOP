// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Branch.h"

#include <string>
using std::string;

Branch::Branch(const string& location) : location(location) {};

Branch::~Branch(){
    for(int i=0; i < this->items; i++){
        delete this->catalog[i];
    }
}

void Branch::addItem(Item* item){
    if(this->items < STORE_SIZE){ // array is not full
        // add item in next available spot
        this->catalog[this->next_index++] = item;
        this->items++;
    }
    else{ // array is full
        if(next_index >= STORE_SIZE){
            this->next_index = 0;
        }
        // delete and replace with item
        delete this->catalog[this->next_index];
        this->catalog[this->next_index++] = item;
    }
}

int Branch::getItems() const{
    return this->items;
}
Item** Branch::getCatalog(int& num){
    num = this->items;
    return this->catalog;
}
string Branch::getLocation() const{
    return this->location;
}
void Branch::setLocation(const string& location){
    this->location = location;
}
