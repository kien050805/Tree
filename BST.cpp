#include <iostream>
#include "BST.hpp"
#include "BSTNode.hpp"
#include "customexceptions.hpp"

using namespace std;

/*===========================================================================
Default constructor
Creates a new binary search tree with type T
Parameters: None
Return: None
===========================================================================*/
template <class T>
BST<T>::BST(void)
{
    root = nullptr;
    bst_size = 0;
};

template <class T>
BST<T>::BST(const BST<T> &tree){};

template <class T>
BST<T>::~BST(void)
{
    deallocate(root);
};

template <class T>
BST<T> BST<T>::operator=(const BST<T> &tree) {};

template <class T>
void BST<T>::deallocate(BSTNode<T> *node)
{
    if (node->left != nullptr)
    {
        deallocate(node->left);
    };
    if (node->right != nullptr)
    {
        deallocate(node->right);
    };
    delete node;
};

/*===========================================================================
transplant function
Replaces one subtree as a child of its parent with another subtree
Parameters: Pointer to current subtree, pointer to new subtree
Return: None
===========================================================================*/
template <class T>
void BST<T>::transplant(BSTNode<T> *oldNode, BSTNode<T> *newNode)
{
    if (oldNode->p == nullptr)
    {
        root = newNode;
    }
    else if (oldNode == oldNode->p->left)
    {
        oldNode->p->left = newNode;
    }
    else
    {
        oldNode->p->right = newNode;
    }
    if (newNode != nullptr)
    {
        newNode->p = oldNode->p;
    }
};

/*===========================================================================
isEmpty function
Check if the tree is empty or not
Parameters: None
Return: True if the tree is empty, false if isn't
===========================================================================*/
template <class T>
bool BST<T>::isEmpty() const
{
    return (bst_size == 0);
};

/*===========================================================================
size function
Returns the size of the binary search tree
Parameters: None
Return: The size of the binary search tree
===========================================================================*/
template <class T>
long BST<T>::size() const
{
    return bst_size;
};

/*===========================================================================
insert function
Inserts a node with value value into the tree and returns
a pointer to the inserted node.
Parameters: The value to be inserted
Return: The pointer to the inserted node
===========================================================================*/
template <class T>
BSTNode<T> *BST<T>::insert(T value)
{
    BSTNode<T> *z = new BSTNode<T>(value);
    BSTNode<T> *x = root;
    BSTNode<T> *y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        };
    };
    z->p = y;
    if (y == nullptr)
    {
        root = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    bst_size++;
    return z;
};

/*===========================================================================
remove function
Removes a node with value value from the tree.
Parameters: The value to be removed
Return: None
===========================================================================*/
template <class T>
void BST<T>::remove(T value)
{
    if (isEmpty())
    {
        throw empty_tree_exception();
    }

    BSTNode<T> *z = search(value);

    if (z == nullptr)
    {
        throw value_not_in_tree_exception();
    }

    if (z->left == nullptr)
    {
        transplant(z, z->right);
    }
    else if (z->right == nullptr)
    {
        transplant(z, z->left);
    }
    else
    {
        BSTNode<T> *y = z->right->treeMin();
        if (y != z->right)
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(value, y);
        y->left = value->left;
        y->left->p = y;
    }

    bst_size--;
};

/*===========================================================================
search function
Returns a pointer to a node with value value.
Parameters: The value to be searched
Return: The pointer of the value in the tree
===========================================================================*/
template <class T>
BSTNode<T> *BST<T>::search(T value) const
{
    BSTNode<T> x = root;
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

/*===========================================================================
treeMin function
Find the pointer of the smallest value of the binary search tree
Parameters: None
Return: The pointer of the smallest value of the binary search tree
===========================================================================*/
template <class T>
BSTNode<T> *BST<T>::treeMin() const
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

/*===========================================================================
treeMax function
Find the pointer of the largest value of the binary search tree
Parameters: None
Return: The pointer of largest value of the binary search tree
===========================================================================*/
template <class T>
BSTNode<T> *BST<T>::treeMax() const
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

/*===========================================================================
printPreOrderTraversal function
Prints the tree in pre-order traversal
Parameters: None
Return: None
===========================================================================*/
template <class T>
void BST<T>::printPreOrderTraversal() const
{
    root->printPreOrderTraversal();
};

/*===========================================================================
printInOrderTraversal function
Prints the tree in in-order traversal
Parameters: None
Return: None
===========================================================================*/
template <class T>
void BST<T>::printInOrderTraversal() const
{
    root->printInOrderTraversal();
};

/*===========================================================================
printPostOrderTraversal function
Prints the tree in post-order traversal
Parameters: None
Return: None
===========================================================================*/
template <class T>
void BST<T>::printPostOrderTraversal() const
{
    root->printPostOrderTraversal();
};
