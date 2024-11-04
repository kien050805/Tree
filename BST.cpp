#include <iostream>
#include "BST.hpp"
#include "customexceptions.hpp"

using namespace std;

/*===========================================================================
Default constructor
Creates a new binary search tree with type T
Parameters: None
Return: None
===========================================================================*/
template <class T>
BST<T>::        BST(void){
    root = NULL;
    size = 0;
};

template <class T>
BST<T>::        BST(const BST<T> &tree){

};

template <class T>
BST<T>::        ~BST(void){

};

template <class T>
BST<T>          BST<T>::operator=   (const BST<T> &tree){

};

template <class T>
void            BST<T>::transplant  (BSTNode<T> *oldNode, BSTNode<T> *newNode){

};

/*===========================================================================
isEmpty function
Check if the tree is empty or not
Parameters: None
Return: True if the tree is empty, false if isn't
===========================================================================*/
template <class T>
bool            BST<T>::isEmpty     ()      const{
    return (bst_size == 0);
};

/*===========================================================================
size function
Returns the size of the binary search tree
Parameters: None
Return: The size of the binary search tree
===========================================================================*/
template <class T>
long            BST<T>::size        ()      const{
    return bst_size;
};

template <class T>
BSTNode<T>*     BST<T>::insert      (T value){

};

template <class T>
void            BST<T>::remove      (T value){

};

template <class T>
BSTNode<T>*     BST<T>::search      (T value)   const{

};

/*===========================================================================
treeMin function
Find the pointer of the smallest value of the binary search tree
Parameters: None
Return: The pointer of the smallest value of the binary search tree
===========================================================================*/
template <class T>
BSTNode<T>*     BST<T>::treeMin     ()          const{
    if isEmpty(){
        throw empty_tree_exception();
    }
    else {
        BSTNode<T>* x = root;
        while x->left != NULL{
            x = x->left;
        }
        return x;
    }
};

/*===========================================================================
treeMax function
Find the pointer of the largest value of the binary search tree
Parameters: None
Return: The pointer of largest value of the binary search tree
===========================================================================*/
template <class T>
BSTNode<T>*     BST<T>::treeMax     ()          const{
    if isEmpty(){
        throw empty_tree_exception();
    }
    else {
        BSTNode<T>* x = root;
        while x->right != NULL{
            x = x->right;
        }
        return x;
    }
};

/*===========================================================================
printPreOrderTraversal function
Find the pointer of the largest value of the binary search tree
Parameters: None
Return: The pointer of largest value of the binary search tree
===========================================================================*/
template <class T>
void            BST<T>::printPreOrderTraversal()          const{

};

template <class T>
void            BST<T>::printInOrderTraversal()          const{

};

template <class T>
void            BST<T>::printPostOrderTraversal()          const{

};
