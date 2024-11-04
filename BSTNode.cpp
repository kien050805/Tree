#include <iostream>
#include "BSTNode.hpp"

using namespace std;

template <class T>
BSTNode<T>::BSTNode(T key)
{
    *this = new Node;
    this.key = key;
    this.p = NULL;
    this.left = NULL;
    this.right = NULL;
};

template <class T>
BSTNode<T>::BSTNode(const BSTNode<T> &BSTNode){};

template <class T>
BSTNode<T>::~BSTNode(void){
    delete this};

template <class T>
BSTNode<T>::operator=(const BSTNode<T>){};

template <class T>
BSTNode<T> *BSTNode<T>::treeMin() const
{
    if (this.left == NULL)
    {
        return *this;
    };
    else
    {
        return this.left;
    }
};

template <class T>
BSTNode<T> *BSTNode<T>::treeMax() const
{
    if (this.right == NULL)
    {
        return *this;
    };
    else
    {
        return this.right;
    }
};

template <class T>
void BSTNode<T>::printPreOrderTraversal() const
{
    if (this != NULL)
    {
        cout << this.key;
        printInOrderTraversal(this.left);
        printInOrderTraversal(this.right);
    };
};

template <class T>
void BSTNode<T>::printInOrderTraversal() const
{
    if (this != NULL)
    {
        printInOrderTraversal(this.left);
        cout << this.key;
        printInOrderTraversal(this.right);
    };
};

template <class T>
void BSTNode<T>::printPostOrderTraversal() const
{
    if (this != NULL)
    {
        printInOrderTraversal(this.left);
        printInOrderTraversal(this.right);
        cout << this.key;
    };
};
