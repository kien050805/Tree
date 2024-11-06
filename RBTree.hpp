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
		long			    rbt_size;	

		void			    deallocate 					( RBTreeNode<T> *node );
        RBTreeNode<T>*      copy                        ( const RBTreeNode<T> *node );
        void                left_rotate                 ( RBTreeNode<T>* node);
        void                right_rotate                ( RBTreeNode<T>* node);

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

};


#endif