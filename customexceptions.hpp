#include <iostream>
#include <exception>
using namespace std;

#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

class value_not_in_tree_exception : public exception {
public:
    const char* what() const throw() {
        return "Error: The specified value is not in the tree.";
    }
};

class empty_tree_exception : public exception {
public:
    const char* what() const throw() {
        return "Error: This is an empty tree.";
    }
};

#endif