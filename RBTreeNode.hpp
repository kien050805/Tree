/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
RBTreeNode.hpp
This file contains the definitions of the red-black tree functions.
===========================================================================*/


#include <iostream>
#include <string>
using namespace std;

#ifndef RBTREENODE_HPP
#define RBTREENODE_HPP

template <class T>
class RBTree;

template <class T>
class RBTreeNode
{
    private:
        T key;
        bool color; //False is Red, True is Black
        RBTreeNode<T> *p;
        RBTreeNode<T> *left;
        RBTreeNode<T> *right;

    public:
                        RBTreeNode                  (T item);
                        RBTreeNode                  ();
                        RBTreeNode                  (const RBTreeNode<T> &node);
                        ~RBTreeNode                 (void);
        RBTreeNode<T>*  operator=	                (const RBTreeNode<T> &node);

        RBTreeNode<T>*  treeMin                     ();
        RBTreeNode<T>*  treeMax                     ();
        void            printPreOrderTraversal      () const;
        void            printInOrderTraversal       () const;
        void            printPostOrderTraversal     () const;
        T               value                       ();

        friend class RBTree<T>;
};

#endif