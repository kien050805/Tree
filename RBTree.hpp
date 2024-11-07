/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
RBTree.hpp
This file contains the definitions of the red-black tree functions.
===========================================================================*/

#include <iostream>

using namespace std;

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "RBTreeNode.hpp"

template <class T> 
class RBTree
{
	private:
		RBTreeNode<T>*      root;
        RBTreeNode<T>*      NIL;
		long			    rbt_size;	

		void			    deallocate 					( RBTreeNode<T> *node );
        RBTreeNode<T>*      copy                        ( const RBTreeNode<T> *node, const RBTree<T> &tree );
        void                left_rotate                 ( RBTreeNode<T>* node);
        void                right_rotate                ( RBTreeNode<T>* node);
        void                insert_fixup                ( RBTreeNode<T>* z);
        void                delete_fixup                ( RBTreeNode<T>* x);

	public: 
						    RBTree		                ( void );
						    RBTree		                ( const RBTree<T> &tree );
						    ~RBTree		                ( void );
		RBTree<T>			operator=	                ( const RBTree<T> &tree );

        void                transplant                  (RBTreeNode<T> *oldNode, RBTreeNode<T> *newNode);
        bool                isEmpty                     () const;
        long                size                        () const;
        RBTreeNode<T>*      insert                      (T value);
        void        	    remove                      (T value);
        RBTreeNode<T>* 	    search                      (T value) const;
        RBTreeNode<T>* 	    treeMin                     () const;
        RBTreeNode<T>* 	    treeMax                     () const;
        void        	    printPreOrderTraversal      () const;
        void        	    printInOrderTraversal       () const;
        void        	    printPostOrderTraversal     () const;
        
        friend class RBTreeNode<T>;
};


#endif