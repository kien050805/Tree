/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
BST.hpp
This file contains the definitions of the binary search tree functions.
===========================================================================*/

#include <iostream>

using namespace std;

#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"

template <class T> 
class BST
{
	private:
		BSTNode<T>		*root;
		long			bst_size;	

		void			deallocate 					( BSTNode<T> *node );
        BSTNode<T>*     copy                        ( const BSTNode<T> *node );
	public:
						BST		                    ( void );
						BST		                    ( const BST<T> &tree );
						~BST		                ( void );
		BST<T>			operator=	                ( const BST<T> &tree );

        void        	transplant                  ( BSTNode<T> *oldNode, BSTNode<T> *newNode);
		bool        	isEmpty                     () const;
        long        	size                        () const;
        BSTNode<T>* 	insert                      (T value);
        void        	remove                      (T value);
        BSTNode<T>* 	search                      (T value) const;
        BSTNode<T>* 	treeMin                     () const;
        BSTNode<T>* 	treeMax                     () const;
        void        	printPreOrderTraversal      () const;
        void        	printInOrderTraversal       () const;
        void        	printPostOrderTraversal     () const;

};


#endif
