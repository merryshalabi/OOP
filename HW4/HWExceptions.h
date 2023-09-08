// Student1 Albert Khayat, 1albertkhayat1@gmail.com, 212747026.
// Student2 Merry Shalabi, merryshalabi@gmail.com, 324007202.

#ifndef HWEXCEPTIONS_H
#define HWEXCEPTIONS_H

#include <exception>

class ExistingItemError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to add an item with an id already in the catalog";
    }
};

class FullCatalogError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to add an item to a full catalog";
    }
};

class NonExistingItemError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to delete an item with a non existing id";
    }
};

class NoneExistingItemTypeError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to get an item with a non existing type";
    }
};

class ConnectError : public std::exception
{
    const char* what() const throw () override
    {
        return "Failed connection attempt";
    }
};

#endif
