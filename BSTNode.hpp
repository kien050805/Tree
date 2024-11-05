/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
BSTNode.hpp
This file contains the definitions of the sorting functions.
===========================================================================*/


#include <iostream>
#include <string>
using namespace std;

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

template <class T>
class BST;

template <class T>
class BSTNode
{
    private:
        T key;
        BSTNode<T> *p;
        BSTNode<T> *left;
        BSTNode<T> *right;

    public:


                        BSTNode                 (T item);
                        BSTNode                 (const BSTNode<T> &node);
                        ~BSTNode                (void);
        BSTNode<T>*		operator=	            (const BSTNode<T> &node);

        BSTNode<T>*     treeMin                 ();
        BSTNode<T>*     treeMax                 ();
        void            printPreOrderTraversal  () const;
        void            printInOrderTraversal   () const;
        void            printPostOrderTraversal () const;

        friend class BST<T>;
};

#endif