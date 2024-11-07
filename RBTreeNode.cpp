#include <iostream>
#include "RBTreeNode.hpp"

using namespace std;

template<class T>
RBTreeNode<T>::RBTreeNode()
{
    color = true;
    p = this;
    left = this;
    right = this;
};

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
    if (left == left->left)
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
    if (right == right->right)
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
    if (left != right->right)
    {
        left->printPreOrderTraversal();
    };
    if (right != right->right)
    {
        right->printPreOrderTraversal();
    };
};

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

template <class T>
void RBTreeNode<T>::printPostOrderTraversal() const
{
    if (left == left->left)
    {
        left->printPostOrderTraversal();
    };
    if (right != right->right)
    {
        right->printPostOrderTraversal();
    };
    cout << key << " ";
};
