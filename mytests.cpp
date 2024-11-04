#include <iostream>
#include "BSTNode.hpp"
#include "BSTNode.cpp"
#include "BST.hpp"
#include "BST.cpp"
#include "RBTreeNode.hpp"
#include "RBTreeNode.cpp"
#include "RBTree.hpp"
#include "RBTree.cpp"

/*===========================================================================
BSTNode_sanity_check()
Run a series of predefined test cases to ensure that the BSTNode class is 
functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
bool BSTNode_sanity_check()
{
    bool check = true;


    
    return check;
};

/*===========================================================================
BST_sanity_check()
Run a series of predefined test cases to ensure that the BST class is 
functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
bool BST_sanity_check()
{
    bool check = true;
    // Create a BST
    BST<long> tree;

    // Test isEmpty on an empty tree
    if (!tree.isEmpty()){
        check = false;
    };

    // Test insert
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Test size
    if (tree.size() != 7){
        check = false;
    };

    return check;
};

/*===========================================================================
RBTNode_sanity_check()
Run a series of predefined test cases to ensure that the RBTNode class is 
functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
bool RBTNode_sanity_check()
{
    bool check = true;

    
    return check;
};

/*===========================================================================
RBT_sanity_check()
Run a series of predefined test cases to ensure that the RBT class is 
functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
bool RBT_sanity_check()
{
    bool check = true;

    
    return check;
};


int main()
{

    return 0;
};