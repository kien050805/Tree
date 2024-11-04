/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
BST.hpp
This file contains the definitions of the binary search tree implementations
===========================================================================*/

#include <iostream>
using namespace std;

#include "BSTNode.hpp"

#ifndef BST_HPP
#define BST_HPP

template <class T> 
class BST
{
	private:
		// struct for Node for Binary Search Tree
		struct Node
		{
			T		key;
            Node    *p;
			Node 	*left;
            Node    *right;
		};
		Node		*root;
		long		size;	

	public:
					BST		                    ( void );
					BST		                    ( const BST<T> &tree );
					~BST		                ( void );
		BST<T>		operator=	                ( const BST<T> &tree );

        void        transplant                  ( BSTNode<T> *oldNode, BSTNode<T> *newNode);
		bool        isEmpty()                   const;
        long        size()                      const;
        BSTNode<T>* insert                      (T value);
        void        remove                      (T value);
        BSTNode<T>* search                      (T value) const;
        BSTNode<T>* treeMin()                   const;
        BSTNode<T>* treeMax()                   const;
        void        printPreOrderTraversal()    const;
        void        printInOrderTraversal()     const;
        void        printPostOrderTraversal()   const;

};

#include "BST.cpp"
#endif
