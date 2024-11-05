#include <iostream>
#include "BSTNode.hpp"

using namespace std;

template <class T>
BSTNode<T>::BSTNode(T item)
{
    key = item;
    left = nullptr;
    right = nullptr;
    p = nullptr;
};

template <class T>
BSTNode<T>::BSTNode(const BSTNode<T> &node)
{
    key = node.key;
    left = node.left;
    right = node.r;
    p = node.p;
};

template <class T>
BSTNode<T>::~BSTNode(void){};

template <class T>
BSTNode<T> *BSTNode<T>::operator=(const BSTNode<T> &node)
{
    key = node.key;
    left = node.left;
    right = node.r;
    p = node.p;
};

template <class T>
BSTNode<T> *BSTNode<T>::treeMin() const
{
    if (left == nullptr)
    {
        return *this;
    }
    else
    {
        return left->treeMin();
    };
};

template <class T>
BSTNode<T> *BSTNode<T>::treeMax() const
{
    if (right == nullptr)
    {
        return *this;
    }
    else
    {
        return right->treeMax();
    };
};

template <class T>
void BSTNode<T>::printPreOrderTraversal() const
{

    cout << key;
    if (left != nullptr)
    {
        left -> printPreOrderTraversal();
    };
    if (right != nullptr)
    {
        right -> printPreOrderTraversal();
    };
};

template <class T>
void BSTNode<T>::printInOrderTraversal() const
{
    if (left != nullptr)
    {
        left -> printInOrderTraversal();
    };
    cout << key;
    if (right != nullptr)
    {
        right -> printInOrderTraversal();
    };
};

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
    cout << key;
};
