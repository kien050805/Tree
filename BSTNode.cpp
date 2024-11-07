/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
BSTNode.cpp
This file contains the implementations of the binary search tree functions.
===========================================================================*/ 

#include <iostream>
#include "BSTNode.hpp"

using namespace std;

/*===========================================================================
Default constructor
Creates a new binary search tree node with type T key
Parameters: an item of type T
Return: None
===========================================================================*/
template <class T>
BSTNode<T>::BSTNode(T item)
{
    key = item;
    left = nullptr;
    right = nullptr;
    p = nullptr;
};

/*===========================================================================
Default copy constructor
Copy a binary search tree node to a new binary search tree node both with 
type T
Parameters: node with value of type T
Return: None
===========================================================================*/
template <class T>
BSTNode<T>::BSTNode(const BSTNode<T> &node)
{
    key = node.key;
    left = node.left;
    right = node.r;
    p = node.p;
};

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class T>
BSTNode<T>::~BSTNode(void){};

/*===========================================================================
Assignment operator
Overloading the = operator to assign a binary search tree node, functions
similar to the copy constructor
Parameters: A binary search tree node with value of type T
Return: A copied binary search tree node with value of type T
===========================================================================*/
template <class T>
BSTNode<T> *BSTNode<T>::operator=(const BSTNode<T> &node)
{
    key = node.key;
    left = node.left;
    right = node.r;
    p = node.p;
};

/*===========================================================================
treeMin function
Find the pointer of the smallest value of the sub binary search tree from a 
parent node
Parameters: None
Return: The pointer of the smallest value of the sub binary search tree
===========================================================================*/
template <class T>
BSTNode<T> *BSTNode<T>::treeMin()
{
    if (left == nullptr)
    {
        return this;
    }
    else
    {
        return left->treeMin();
    };
};

/*===========================================================================
treeMax function
Find the pointer of the largest value of the sub binary search tree from a
parent node
Parameters: None
Return: The pointer of largest value of the sub binary search tree
===========================================================================*/
template <class T>
BSTNode<T> *BSTNode<T>::treeMax()
{
    if (right == nullptr)
    {
        return this;
    }
    else
    {
        return right->treeMax();
    };
};

/*===========================================================================
printPreOrderTraversal function
Prints the sub tree in pre-order traversal from a parent node
Parameters: None
Return: None
===========================================================================*/
template <class T>
void BSTNode<T>::printPreOrderTraversal() const
{
    cout << key << " ";
    if (left != nullptr)
    {
        left -> printPreOrderTraversal();
    };
    if (right != nullptr)
    {
        right -> printPreOrderTraversal();
    };
};

/*===========================================================================
printInOrderTraversal function
Prints the sub tree in in-order traversal from a parent node
Parameters: None
Return: None
===========================================================================*/
template <class T>
void BSTNode<T>::printInOrderTraversal() const
{
    if (left != nullptr)
    {
        left -> printInOrderTraversal();
    };
    cout << key << " ";
    if (right != nullptr)
    {
        right -> printInOrderTraversal();
    };
};

/*===========================================================================
printPostOrderTraversal function
Prints the sub tree in post-order traversal from a parent node
Parameters: None
Return: None
===========================================================================*/
template <class T>
void BSTNode<T>::printPostOrderTraversal() const
{
    if (left != nullptr)
    {
        left -> printPostOrderTraversal();
    };
    if (right != nullptr)
    {
        right -> printPostOrderTraversal();
    };
    cout << key << " ";
};

/*===========================================================================
value function
Prints the value mapped to the pointer
Parameters: None
Return: Value type T
===========================================================================*/
template <class T>
T BSTNode<T>::value()
{
    return key;
};