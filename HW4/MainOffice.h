// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef MAINOFFICE_H
#define MAINOFFICE_H

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Branch.h"

using std::map;
using std::vector;
using std::string;

class MainOffice
{
private:
    map<string, Branch> branches;
    vector<string> locations; // all current keys in branches map

    MainOffice() {};
    ~MainOffice();
    MainOffice(const MainOffice& other) = delete; // should not copy
    MainOffice& operator=(const MainOffice& other) = delete; // should not assign
public:

    void addBranch(const string& location,int capacity);
    void deleteBranch(const string& location);

    void printByLocation() const;
    
    static MainOffice& getInstance();
    map<string, Branch>& getBranches();
    vector<string>& getLocations();

};

class ExistingBranchError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to add a branch with an already existing location";
    }
};

class NonExistingBranchError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to delete a branch with an non existing location";
    }
};

#endif