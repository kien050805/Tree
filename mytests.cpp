#include <iostream>
#include "BSTNode.hpp"
#include "BSTNode.cpp"
#include "BST.hpp"
#include "BST.cpp"
#include "RBTreeNode.hpp"
#include "RBTreeNode.cpp"
#include "RBTree.hpp"
#include "RBTree.cpp"
#include "string"

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
    // Create BSTs
    BST<int> tree_0;
    BST<string> tree_1;
    BST<double> tree_2;
    BST<int> tree_3;

    // Test isEmpty on an empty tree
    if (!tree_0.isEmpty()){
        check = false;
    };

    // Test insert int
    tree_0.insert(10);
    tree_0.insert(-5);
    tree_0.insert(15);
    tree_0.insert(7);
    tree_0.insert(-12);

    if (tree_0.size() != 5){
        check = false;
    };

    // Test insert string
    tree_1.insert("b");
    tree_1.insert("f");
    tree_1.insert("d");
    tree_1.insert(".");
    tree_1.insert(",");

    if (tree_1.size() != 5){
        check = false;
    };

    // Test insert double
    tree_2.insert(1.21);
    tree_2.insert(2.1);
    tree_2.insert(12.3);
    tree_2.insert(0.55);
    tree_2.insert(1.7);

    if (tree_2.size() != 5){
        check = false;
    };

    // Test insert same values
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);

    if (tree_3.size() != 5){
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