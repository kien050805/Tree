#include <iostream>
#include "RBTree.hpp"
#include "RBTreeNode.hpp"
#include "customexceptions.hpp"

using namespace std;

template <class T>
RBTree<T>::RBTree(void){};

template <class T>
RBTree<T>::RBTree(const RBTree<T> &tree){};

template <class T>
RBTree<T>::~RBTree(void){};

template <class T>
RBTree<T> RBTree<T>::operator=(const RBTree<T> &tree) {};

template <class T>
void RBTree<T>::deallocate(RBTreeNode<T> *node) {};

template <class T>
RBTreeNode<T> *RBTree<T>::copy(const RBTreeNode<T> *node) {};

template <class T>
void RBTree<T>::left_rotate(RBTreeNode<T> *node) {};

template <class T>
void RBTree<T>::right_rotate(RBTreeNode<T> *node) {};

template <class T>
void RBTree<T>::transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode) {};

template <class T>
bool RBTree<T>::isEmpty() const {};

template <class T>
long RBTree<T>::size() const {};

template <class T>
RBTreeNode<T> *RBTree<T>::insert(T value) {};

template <class T>
void RBTree<T>::remove(T value) {};

template <class T>
RBTreeNode<T> *RBTree<T>::search(T value) const 
{
        RBTreeNode<T> *x = root;
    while (x != nullptr && value != x->key)
    {
        if (value < x->key)
        {
            x = x->left;
        }
        else
            x = x->right;
    }
    return x;
};

template <class T>
RBTreeNode<T> *RBTree<T>::treeMin() const 
{
        if (isEmpty())
    {
        throw empty_tree_exception();
    }
    else
    {
        return root->treeMin();
    }
};

template <class T>
RBTreeNode<T> *RBTree<T>::treeMax() const 
{
        if (isEmpty())
    {
        throw empty_tree_exception();
    }
    else
    {
        return root->treeMax();
    }
};

template <class T>
void RBTree<T>::printPreOrderTraversal() const 
{
    root->printPreOrderTraversal();
};

template <class T>
void RBTree<T>::printInOrderTraversal() const 
{
    root->printInOrderTraversal();
};

template <class T>
void RBTree<T>::printPostOrderTraversal() const 
{
    root->printPostOrderTraversal();
};