#include <iostream>
#include <exception>
using namespace std;

#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

class value_not_in_tree_exception : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: The specified value is not in the tree.";
    }
};

class empty_tree_exception : public std::exception {
public:
    // Override the what() function to provide an error message
    const char* what() const noexcept override {
        return "Error: This is an empty tree.";
    }
};

template <class T> 
class BST
{
	private:
		// struct for Node for Binary Search Tree
		struct Node
		{
			T		key;
            Node    *p;
			Node 	*left;
            Node    *right;
		};
		Node		*root;
		long		size;	

	public:
        bool isEmpty() const {
            return size == 0;
        }

        void checkEmpty() {
            if (isEmpty()) {
                throw empty_tree_exception();
            }
        }
};

#endif