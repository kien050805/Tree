#include <iostream>
#include "BSTNode.hpp"

using namespace std;

template <class T>
BSTNode<T>:: BSTNode(void)
{};

template <class T>
BSTNode<T>:: BSTNode(const BSTNode<T> &BSTNode)
{};

template <class T>
BSTNode<T>:: ~BSTNode(void)
{};

template <class T>
BSTNode<T>:: operator= (const BSTNode<T>)
{};

template <class T>
BSTNode<T>* BSTNode<T>:: treeMin() const
{};

template <class T>
BSTNode<T>*  BSTNode<T>:: treeMax() const
{};

template <class T>
void            BSTNode<T>::printPreOrderTraversal()          const{

};

template <class T>
void            BSTNode<T>::printInOrderTraversal()           const{

};

template <class T>
void            BSTNode<T>::printPostOrderTraversal()         const{

};
