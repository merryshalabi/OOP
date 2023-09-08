// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "Branch.h"

Branch::Branch(const string& location, int capacity) : location(location), capacity(capacity) {}

Branch::Branch() : location("~"), capacity(0) {}

Branch::~Branch()
{
    // Note that catalog.clear() does not destruct pointer objects
    for(Item* vecItem : this->catalog)
    {
        delete vecItem;
    }
}

Branch::Branch(const Branch& other) : location(other.location), capacity(other.capacity) {}

void Branch::addItem(Item* item){

    // Check if catalog is full
    if(this->catalog.size() >= this->capacity)
    {
        throw FullCatalogError();
    }

    // Look for item in catalog
    for(Item* vecItem : this->catalog)
    {
        if(vecItem == item) throw ExistingItemError();
    }

    // No errors, add item
    this->catalog.push_back(item);
}

Item* Branch::deleteItem(int id)
{
    Item* deletedItem = NULL;

    // go over catalog and find item with given id
    for(int i=0; i < this->catalog.size(); i++)
    {
        if(this->catalog[i]->getId() == id)
        {
            deletedItem = catalog[i]; // save deleted item pointer
            this->catalog.erase(this->catalog.begin()+i); // delete item pointer from catalog
            return deletedItem;
        }
    }
    if(deletedItem == NULL) throw NonExistingItemError();

    return deletedItem;
}

int Branch::calculateValue() const
{
    int value = 0;
    for(Item* vecItem : this->catalog) // go over catalog
    {
        value += vecItem->getPrice();
    }
    return value;
}

bool Branch::compareByPrice(Item* a,Item* b)
{
    return (a->getPrice() < b->getPrice()) ? true : false;
}
bool Branch::compareById(Item* a,Item* b)
{
    return (a->getId() < b->getId()) ? true : false;
}

void Branch::printBranchInfo() const
{
    std::cout << "Printing KSF branch in " + this->location << std::endl;
    std::cout << "There are " + std::to_string(this->catalog.size()) + " item in the catalog" << std::endl;
    std::cout << "Catalog value is: " + std::to_string(calculateValue()) << std::endl;
}
void Branch::printItemVector(vector<Item*> vec) const
{
    for(Item* vecItem : vec) // go over vector
    {
        std::cout << string(*vecItem) << std::endl;
    }
}

void Branch::print_catalog_by_price() const
{
    vector<Item*> catalogCopy = this->catalog;
    std::stable_sort(catalogCopy.begin(), catalogCopy.end(), compareByPrice); // sort items by price (stable)

    printBranchInfo();
    printItemVector(catalogCopy);
}
void Branch::print_catalog_by_id() const
{
    vector<Item*> catalogCopy = this->catalog;
    std::sort(catalogCopy.begin(), catalogCopy.end(), compareById); // sort items by Id

    printBranchInfo();
    printItemVector(catalogCopy);
}

vector<Item*>& Branch::getCatalog(void)
{
    return this->catalog;
}
int Branch::getCapacity() const
{
    return this->capacity;
}
string Branch::getLocation() const
{
    return this->location;
}
void Branch::setLocation(const string& location)
{
    this->location = location;
}
