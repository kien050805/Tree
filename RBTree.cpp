/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
RBTree.cpp
This file contains the implementations of the red-black tree functions.
===========================================================================*/ 

#include <iostream>
#include "RBTree.hpp"
#include "RBTreeNode.hpp"
#include "customexceptions.hpp"

using namespace std;

/*===========================================================================
Default constructor
Creates a new red black tree with type T
Parameters: None
Return: None
===========================================================================*/
template <class T>
RBTree<T>::RBTree(void)
{
    NIL = new RBTreeNode<T>();
    root = NIL;
    rbt_size = 0;
};

/*===========================================================================
Default copy constructor
Copy a red black tree to a new red black tree both with type T
Parameters: None
Return: None
===========================================================================*/
template <class T>
RBTree<T>::RBTree(const RBTree<T> &tree)
{
    NIL = new RBTreeNode<T>();
    root = copy(tree.root, tree);
    rbt_size = tree.rbt_size;
};

/*===========================================================================
Default destructor
Parameters: None
Return: None
===========================================================================*/
template <class T>
RBTree<T>::~RBTree(void)
{
    deallocate(root);
    delete NIL;
};

/*===========================================================================
Assignment operator
Overloading assignment operator to assign a red-black tree, functions similar
to the copy constructor
Parameters: A red-black tree type T
Return: A copied red-black tree type T
===========================================================================*/
template <class T>
RBTree<T> RBTree<T>::operator=(const RBTree<T> &tree)
{
    deallocate(root);
    root = copy(tree.root, tree);
    rbt_size = tree.rbt_size;
    return *this;
};

/*===========================================================================
The deallocate helper function
Recursively delete all nodes that belong to the given parent node (included)
Parameters: A node of a red-black tree type T
Return: None
===========================================================================*/
template <class T>
void RBTree<T>::deallocate(RBTreeNode<T> *node)
{
    if (node == NIL)
    {
        return;
    };
    if (node->left != NIL)
    {
        deallocate(node->left);
    };
    if (node->right != NIL)
    {
        deallocate(node->right);
    };
    delete node;
};

/*===========================================================================
The copy helper function
Copy a (sub) red-black tree from a given parent node to a new red-black
tree both with type T
Parameters: A node of a red-black tree type T
Return: A copied red-black tree type T
===========================================================================*/
template <class T>
RBTreeNode<T> *RBTree<T>::copy(const RBTreeNode<T> *node, const RBTree<T> &tree)
{
    RBTreeNode<T> *z = new RBTreeNode<T>(node->key);
    z->color = node->color;

    if (node->right != tree.NIL)
    {
        z->right = copy(node->right, tree);
        z->right->p = z;
    }
    else
    {
        z->right = NIL;
    };
    if (node->left != tree.NIL)
    {
        z->left = copy(node->left, tree);
        z->left->p = z;
    }
    else
    {
        z->left = NIL;
    };
    return z;
};

/*===========================================================================
left_rotate function
Performs a left rotation on the node
Parameters: A node of a red-black tree type T
Return: None
===========================================================================*/
template <class T>
void RBTree<T>::left_rotate(RBTreeNode<T> *node)
{
    RBTreeNode<T> *y = node->right;
    node->right = y->left;
    if (y->left != NIL)
    {
        y->left->p = node;
    };
    y->p = node->p;
    if (node->p == NIL)
    {
        root = y;
    }
    else if (node == node->p->left)
    {
        node->p->left = y;
    }
    else
    {
        node->p->right = y;
    }
    y->left = node;
    node->p = y;
};

/*===========================================================================
right_rotate function
Performs a right rotation on the node
Parameters: A node of a red-black tree type T
Return: None
===========================================================================*/
template <class T>
void RBTree<T>::right_rotate(RBTreeNode<T> *node)
{
    RBTreeNode<T> *y = node->left;
    node->left = y->right;
    if (y->right != NIL)
    {
        y->right->p = node;
    };
    y->p = node->p;
    if (node->p == NIL)
    {
        root = y;
    }
    else if (node == node->p->left)
    {
        node->p->left = y;
    }
    else
    {
        node->p->right = y;
    }
    y->right = node;
    node->p = y;
};

template <class T>
void RBTree<T>::insert_fixup(RBTreeNode<T> *z)
{
    RBTreeNode<T> *y;
    while (z->p->color == false)
    {
        if (z->p == z->p->p->left)
        {
            y = z->p->p->right;
            if (y->color == false)
            {
                z->p->color = true;
                y->color = true;
                z->p->p->color = false;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->right)
                {
                    z = z->p;
                    left_rotate(z);
                }
                z->p->color = true;
                z->p->p->color = false;
                right_rotate(z->p->p);
            };
        }
        else
        {
            y = z->p->p->left;
            if (y->color == false)
            {
                z->p->color = true;
                y->color = true;
                z->p->p->color = false;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->left)
                {
                    z = z->p;
                    right_rotate(z);
                }
                z->p->color = true;
                z->p->p->color = false;
                left_rotate(z->p->p);
            };
        };
    }
    root->color = true;
};

template <class T>
void RBTree<T>::delete_fixup(RBTreeNode<T> *x)
{
    RBTreeNode<T> *w;
    while (x != root && x->color == true)
    {
        if (x == x->p->left)
        {
            w = x->p->right;
            if (w->color == false)
            {
                w->color = true;
                x->p->color = false;
                left_rotate(x->p);
                w = x->p->right;
            };
            if (w->left->color == true && w->right->color == true)
            {
                w->color = false;
                x = x->p;
            }
            else
            {
                if (w->right->color == true)
                {
                    w->left->color = true;
                    w->color = false;
                    right_rotate(w);
                    w = x->p->right;
                };
                w->color = x->p->color;
                x->p->color = true;
                x->right->color = true;
                left_rotate(x->p);
                x = root;
            };
        }
        else
        {
            w = x->p->left;
            if (w->color == false)
            {
                w->color = true;
                x->p->color = false;
                right_rotate(x->p);
                w = x->p->left;
            };
            if (w->right->color == true && w->left->color == true)
            {
                w->color = false;
                x = x->p;
            }
            else
            {
                if (w->left->color == true)
                {
                    w->right->color = true;
                    w->color = false;
                    left_rotate(w);
                    w = x->p->left;
                };
                w->color = x->p->color;
                x->p->color = true;
                x->left->color = true;
                right_rotate(x->p);
                x = root;
            };
        };
        x->color = true;
    }
};

/*===========================================================================
transplant function
Replaces one subtree as a child of its parent with another subtree
Parameters: Pointer to current subtree, pointer to new subtree
Return: None
===========================================================================*/
template <class T>
void RBTree<T>::transplant(RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode)
{
    if (oldNode->p == NIL)
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
    };
    newNode->p = oldNode->p;
};

/*===========================================================================
isEmpty function
Check if the tree is empty or not
Parameters: None
Return: True if the tree is empty, false if isn't
===========================================================================*/
template <class T>
bool RBTree<T>::isEmpty() const
{
    return (rbt_size == 0);
};

/*===========================================================================
size function
Returns the size of the tree
Parameters: None
Return: The size of the tree
===========================================================================*/
template <class T>
long RBTree<T>::size() const
{
    return rbt_size;
};

/*===========================================================================
insert function
Check if the tree is empty or not
Parameters: None
Return: True if the tree is empty, false if isn't
===========================================================================*/
template <class T>
RBTreeNode<T> *RBTree<T>::insert(T value)
{
    RBTreeNode<T> *z = new RBTreeNode<T>(value);
    RBTreeNode<T> *x = root;
    RBTreeNode<T> *y = NIL;
    while (x != NIL)
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
    }
    z->p = y;
    if (y == NIL)
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
    z->left = NIL;
    z->right = NIL;
    z->color = false;
    insert_fixup(z);
    rbt_size ++;
    return z;
};

/*===========================================================================
remove function
Removes a node with value value from the tree.
Parameters: The value to be removed
Return: None
===========================================================================*/
template <class T>
void RBTree<T>::remove(T value)
{
    if (isEmpty())
    {
        throw empty_tree_exception();
    }

    RBTreeNode<T> *z = search(value);

    if (z == NIL)
    {
        throw value_not_in_tree_exception();
    }

    RBTreeNode<T> *y = z;
    RBTreeNode<T> *x;
    bool y_original_color = y->color;
    if (z->left == NIL)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == NIL)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = z->right->treeMin();
        y_original_color = y->color;
        x = y->right;
        if (y != z->right)
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        else
        {
            x->p = y;
            transplant(z, y);
            y->left = z->left;
            y->left->p = y;
            y->color = z->color;
        };
    };
    if (y_original_color == true)
    {
        delete_fixup(x);
    };
    rbt_size--;
};

/*===========================================================================
search function
Returns a pointer to a node with value value.
Parameters: The value to be searched
Return: The pointer of the value in the tree
===========================================================================*/
template <class T>
RBTreeNode<T> *RBTree<T>::search(T value) const
{
    RBTreeNode<T> *x = root;
    while (x != x->p && value != x->key)
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
Find the pointer of the smallest value of the red-black tree
Parameters: None
Return: The pointer of the smallest value of the red-black tree
===========================================================================*/
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

/*===========================================================================
treeMax function
Find the pointer of the largest value of the red-black tree
Parameters: None
Return: The pointer of largest value of the red tree
===========================================================================*/
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

/*===========================================================================
printPreOrderTraversal function
Prints the tree in pre-order traversal
Parameters: None
Return: None
===========================================================================*/
template <class T>
void RBTree<T>::printPreOrderTraversal() const
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
void RBTree<T>::printInOrderTraversal() const
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
void RBTree<T>::printPostOrderTraversal() const
{
    root->printPostOrderTraversal();
};