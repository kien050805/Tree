#include <iostream>
#include "BST.hpp"

using namespace std;

template <class T>
BST<T>::        BST(void){

};

template <class T>
BST<T>::        BST(const BST<T> &tree){

};

template <class T>
BST<T>::        ~BST(void){

};

template <class T>
BST<T>          BST<T>::operator=   (const BST<T>){

};

template <class T>
void            BST<T>::transplant  (BSTNode<T> *oldNode, BSTNode<T> *newNode){

};

template <class T>
bool            BST<T>::isEmpty     ()      const{

};

template <class T>
long            BST<T>::size        ()      const{

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
Find the smallest value of the binary search tree
Parameters: None
Return: The smallest value of the binary search tree
===========================================================================*/
template <class T>
BSTNode<T>*     BST<T>::treeMin     ()          const{
    x = root;
    while x.left != NULL{
        x = x.left;
    }
    return x;
};

/*===========================================================================
treeMax function
Find the largest value of the binary search tree
Parameters: None
Return: The largest value of the binary search tree
===========================================================================*/
template <class T>
BSTNode<T>*     BST<T>::treeMax     ()          const{
    x = root;
    while x.right != NULL{
        x = x.right;
    }
    return x;
};

template <class T>
void            BST<T>::printPreOrderTraversal()          const{

};

template <class T>
void            BST<T>::printInOrderTraversal()          const{

};

template <class T>
void            BST<T>::printPostOrderTraversal()          const{

};
