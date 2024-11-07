/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
RBTreeNode.cpp
This file contains the implementations of the red-black tree functions.
===========================================================================*/ 

#include <iostream>
#include "RBTreeNode.hpp"

using namespace std;

/*===========================================================================
NIL constructor
Creates a new red-black tree node with NIL node
Parameters: None
Return: None
===========================================================================*/
template<class T>
RBTreeNode<T>::RBTreeNode()
{
    color = true;
    p = this;
    left = this;
    right = this;
};

/*===========================================================================
Default constructor
Creates a new red-black tree node with type T key
Parameters: an item of type T
Return: None
===========================================================================*/
template <class T>
RBTreeNode<T>::RBTreeNode(T item)
{
    key = item;
    color = false;
    p = nullptr;
    left = nullptr;
    right = nullptr;
};

/*===========================================================================
Default copy constructor
Copy a red-black tree node to a new red-black tree node both with 
type T
Parameters: node with value of type T
Return: None
===========================================================================*/
template <class T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T> &node)
{
    key = node.key;
    color = node.color;
    p = node.p;
    left = node.left;
    right = node.right;
};

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class T>
RBTreeNode<T>::~RBTreeNode(void){};

/*===========================================================================
Assignment operator
Overloading the assignment to assign a binary search tree node, functions
similar to the copy constructor
Parameters: A binary search tree node with value of type T
Return: A copied binary search tree node with value of type T
===========================================================================*/
template <class T>
RBTreeNode<T> *RBTreeNode<T>::operator=(const RBTreeNode<T> &node)
{
    key = node.key;
    color = node.color;
    p = node.p;
    left = node.left;
    right = node.right;
};

/*===========================================================================
treeMin function
Find the pointer of the smallest value of the sub binary search tree from a 
parent node
Parameters: None
Return: The pointer of the smallest value of the sub binary search tree
===========================================================================*/
template <class T>
RBTreeNode<T> *RBTreeNode<T>::treeMin()
{
    if (left == left->left)
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
RBTreeNode<T> *RBTreeNode<T>::treeMax()
{
    if (right == right->right)
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
void RBTreeNode<T>::printPreOrderTraversal() const
{
    cout << key << " ";
    if (left != right->right)
    {
        left->printPreOrderTraversal();
    };
    if (right != right->right)
    {
        right->printPreOrderTraversal();
    };
};

/*===========================================================================
printInOrderTraversal function
Prints the sub tree in in-order traversal from a parent node
Parameters: None
Return: None
===========================================================================*/
template <class T>
void RBTreeNode<T>::printInOrderTraversal() const
{
    if (left != left -> left)
    {
        left->printInOrderTraversal();
    };
    cout << key << " ";
    if (right != right -> right)
    {
        right->printInOrderTraversal();
    };
};

/*===========================================================================
printPostOrderTraversal function
Prints the sub tree in post-order traversal from a parent node
Parameters: None
Return: None
===========================================================================*/
template <class T>
void RBTreeNode<T>::printPostOrderTraversal() const
{
    if (left != left->left)
    {
        left->printPostOrderTraversal();
    };
    if (right != right->right)
    {
        right->printPostOrderTraversal();
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
T RBTreeNode<T>::value()
{
    return key;
};
