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