// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#include "MainOffice.h"

MainOffice::~MainOffice()
{
    this->branches.clear(); // destroys all branches
}

void MainOffice::addBranch(const string& location,int capacity)
{
    if(this->branches.find(location) != this->branches.end()) // branch with key already exists
    {
        throw ExistingBranchError();
    }
    // branch with key does not exist
    this->locations.push_back(location);
    this->branches.insert({location, Branch(location,capacity)});
}
void MainOffice::deleteBranch(const string& location)
{
    map<string, Branch>::iterator itr = this->branches.find(location);

    if(itr == this->branches.end()) // branch with key does not exist
    {
        throw NonExistingBranchError();
    }
    // branch with key does exist
    this->locations.erase(std::find(this->locations.begin(), this->locations.end(), location));
    this->branches.erase(itr);
}

void MainOffice::printByLocation() const
{
    std::cout << "There are "+std::to_string(this->branches.size())+" KSP branches" << std::endl;

    vector<string> vec = this->locations;
    std::sort(vec.begin(), vec.end()); // sort locations

    for(string location : vec) // go over sorted locations
    {
        this->branches.at(location).print_catalog_by_id(); // print branch from that location
    }
}
MainOffice& MainOffice::getInstance()
{
    static MainOffice mainOffice;
    return mainOffice;
}
map<string, Branch>& MainOffice::getBranches()
{
    return this->branches;
}
vector<string>& MainOffice::getLocations()
{
    return this->locations;
}
