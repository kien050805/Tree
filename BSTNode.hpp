/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
BSTNode.hpp
This file contains the definitions of the sorting functions.
===========================================================================*/


#include <iostream>
#include <string>
using namespace std;

#ifndef BSTNODE
#define BSTNODE

template <class T>
class BSTNode
{
    private:
        struct Node
        {
            T key;
            Node *P;
            Node *left;
            Node *right;
        };
        Node *root;
        void copy(const BSTNode<T> &node);


    public:
                        BSTNode                 (void);
                        BSTNode                 (const BSTNode<T> &node);
                        ~BSTNode                (void);
        BSTNode<T>*     treeMin                 ();
        BSTNode<T>*     treeMax                 ();
        void            printPreOrderTraversal  () const;
        void            printInOrderTraversal   () const;
        void            printPostOrderTraversal () const;
        BSTNode<T>*		operator=	            (const BSTNode<T> &node);
};

#include "BSTNode.cpp"
#endif