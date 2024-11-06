#include <iostream>
#include "RBTreeNode.hpp"

using namespace std;

template <class T>
RBTreeNode<T>::RBTreeNode(T item)
{
    key = item;
    color = false;
    p = nullptr;
    left = nullptr;
    right = nullptr;
};

template <class T>
RBTreeNode<T>::RBTreeNode(const RBTreeNode<T> &node)
{
    key = node.key;
    color = node.color;
    p = node.p;
    left = node.left;
    right = node.right;
};

template <class T>
RBTreeNode<T>::~RBTreeNode(void){};

template <class T>
RBTreeNode<T> *RBTreeNode<T>::operator=(const RBTreeNode<T> &node)
{
    key = node.key;
    color = node.color;
    p = node.p;
    left = node.left;
    right = node.right;
};

template <class T>
RBTreeNode<T> *RBTreeNode<T>::treeMin()
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

template <class T>
RBTreeNode<T> *RBTreeNode<T>::treeMax()
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

template <class T>
void RBTreeNode<T>::printPreOrderTraversal() const
{
    cout << key << " ";
    if (left != nullptr)
    {
        left->printPreOrderTraversal();
    };
    if (right != nullptr)
    {
        right->printPreOrderTraversal();
    };
};

template <class T>
void RBTreeNode<T>::printInOrderTraversal() const
{
    if (left != nullptr)
    {
        left->printInOrderTraversal();
    };
    cout << key << " ";
    if (right != nullptr)
    {
        right->printInOrderTraversal();
    };
};

template <class T>
void RBTreeNode<T>::printPostOrderTraversal() const
{
    if (left != nullptr)
    {
        left->printPostOrderTraversal();
    };
    if (right != nullptr)
    {
        right->printPostOrderTraversal();
    };
    cout << key << " ";
};
