#include <iostream>
#include "BSTNode.hpp"

using namespace std;

template <class T>
BSTNode<T>::BSTNode(T key)
{
    key = key;
    left = NULL;
    right = NULL;
    p = NULL;
};

template <class T>
BSTNode<T>::BSTNode(const BSTNode<T> &node)
{
    key = node.key;
    left = node.left;
    right = node.right;
    p = node.p;
};

template <class T>
BSTNode<T>::~BSTNode(void) {};

template <class T>
BSTNode<T> *BSTNode<T>::operator=(const BSTNode<T> &node)
{
    key = node.key;
    left = node.left;
    right = node.right;
    p = node.p;
};

template <class T>
T BSTNode<T>::value() const
{
    return key;
};


template <class T>
BSTNode<T> *BSTNode<T>::treeMin() const
{
    if (left == NULL)
    {
        return *this;
    };
    else
    {
        return left.treeMin();
    }
};

template <class T>
BSTNode<T> *BSTNode<T>::treeMax() const
{
    if (right == NULL)
    {
        return *this;
    };
    else
    {
        return right.treeMax();
    }
};

template <class T>
void BSTNode<T>::printPreOrderTraversal() const
{
    if (this != NULL)
    {
        cout << key;
        printInOrderTraversal(left);
        printInOrderTraversal(right);
    };
};

template <class T>
void BSTNode<T>::printInOrderTraversal() const
{
    if (this != NULL)
    {
        printInOrderTraversal(left);
        cout << key;
        printInOrderTraversal(right);
    };
};

template <class T>
void BSTNode<T>::printPostOrderTraversal() const
{
    if (this != NULL)
    {
        printInOrderTraversal(left);
        printInOrderTraversal(right);
        cout << key;
    };
};
