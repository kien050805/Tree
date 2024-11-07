/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
customexceptions.hpp
This file contains the custom exceptions for both trees.
===========================================================================*/

#include <iostream>
#include <exception>
using namespace std;

#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

class value_not_in_tree_exception : public exception {
public:
    const char* what() const throw() {
        return "Error: The value is not in the tree.";
    }
};

class empty_tree_exception : public exception {
public:
    const char* what() const throw() {
        return "Error: This is an empty tree.";
    }
};

#endif