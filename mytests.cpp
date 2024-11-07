/*===========================================================================
Kien Le, Nguyen Nguyen, Bach Nguyen
7 November 2024
mytests.cpp
This file contains the sanity checks for both types of trees
===========================================================================*/

#include <iostream>
#include <sstream>
#include <string>
#include "BSTNode.cpp"
#include "BST.cpp"
#include "RBTree.cpp"
#include "RBTreeNode.cpp"

using namespace std;

/*===========================================================================
BST_sanity_check()
Run a series of predefined test cases to ensure that the BST class is 
functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
int BST_sanity_check()
{
    int check = 0;

    // Create BSTs
    BST<int> tree_0;
    BST<string> tree_1;
    BST<double> tree_2;
    BST<int> tree_3;
    BST<int> tree_4;

    // Test exception handling for empty tree
    try {
        tree_0.remove(99); // Attempt to remove a value from an empty tree
        check += 1;
    } catch (const empty_tree_exception& e) {
        // Expected exception for removing from an empty tree
    } catch (...) {
        check += 1;
    }

    // Test isEmpty on an empty tree
    if (!tree_0.isEmpty()){
        check += 1;
    };

    // Test insert int
    tree_0.insert(10);
    tree_0.insert(-5);
    tree_0.insert(15);
    tree_0.insert(7);
    tree_0.insert(-12);

    if (tree_0.size() != 5){
        check += 1;
    };

    // Test insert string
    tree_1.insert("b");
    tree_1.insert("f");
    tree_1.insert("d");
    tree_1.insert(".");
    tree_1.insert(",");

    if (tree_1.size() != 5){
        check += 1;
    };

    // Test insert double
    tree_2.insert(1.21);
    tree_2.insert(2.1);
    tree_2.insert(12.3);
    tree_2.insert(0.55);
    tree_2.insert(1.7);

    if (tree_2.size() != 5){
        check += 1;
    };

    // Test insert same values
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);

    if (tree_3.size() != 5){
        check += 1;
    };

    // Test isEmpty on a tree with values
    if (tree_0.isEmpty()){
        check += 1;
    };

    // Test copy constructor
    BST<int> tree_5(tree_0);
    if (tree_5.size() != 5){
        check += 1;
    };
    
    // Test = operator overloading
    tree_4 = tree_0;
    if (tree_4.size() != 5){
        check += 1;
    };

    // Test remove
    tree_3.remove(0);
    if (tree_3.size() != 4){
        check += 1;
    };

    // Test search
    if (tree_0.search(10)->value() != 10){
        check += 1;
    };

    // Test treeMin
    if (tree_0.treeMin()->value() != -12){
        check += 1;
    }

    // Test treeMax
    if (tree_0.treeMax()->value() != 15){
        check += 1;
    }

    // Test exception handling for value not in tree
    try {
        tree_0.remove(99); // Attempt to remove a non-existent value
        check += 1;
    } catch (const value_not_in_tree_exception& e) {
        // Expected exception for removing a non-existent value
    } catch (...) {
        check += 1;
    }

    // Capture output using ostringstream
    ostringstream ossPreOrder, ossInOrder, ossPostOrder;
    streambuf* originalCoutBuffer = cout.rdbuf();

    // Capture Pre-order traversal
    cout.rdbuf(ossPreOrder.rdbuf());
    tree_0.printPreOrderTraversal();
    // Capture In-order traversal
    cout.rdbuf(ossInOrder.rdbuf());
    tree_0.printInOrderTraversal();
    // Capture Post-order traversal
     cout.rdbuf(ossPostOrder.rdbuf());
    tree_0.printPostOrderTraversal();

    // Restore original cout buffer
    cout.rdbuf(originalCoutBuffer);

    // Test printPreOrderTraversal
    string captured_preorder = ossPreOrder.str();
    if (captured_preorder != "10 -5 -12 7 15 "){
        check += 1;
    };
    // Test printInOrderTraversal
    string captured_inorder = ossInOrder.str();
    if (captured_inorder != "-12 -5 7 10 15 "){
        check += 1;
    };
    // Test printPostOrderTraversal
    string captured_postorder = ossPostOrder.str();
    if (captured_postorder != "-12 7 -5 15 10 "){
        check += 1;
    };
    
    return check;
};

/*===========================================================================
RBT_sanity_check()
Run a series of predefined test cases to ensure that the RBT class is 
functioning correctly.
Parameters: None
Return: boolean value depending on if the function pass the test cases
===========================================================================*/
int RBT_sanity_check()
{
    int check = 0;
    // Create RBTrees
    RBTree<int> tree_0;
    RBTree<string> tree_1;
    RBTree<double> tree_2;
    RBTree<int> tree_3;
    RBTree<int> tree_4;

    // Test exception handling for empty tree
    try {
        tree_0.remove(99); // Attempt to remove a value from an empty tree
        check += 1;
    } catch (const empty_tree_exception& e) {
        // Expected exception for removing from an empty tree
    } catch (...) {
        check += 1;
    }

    // Test isEmpty on an empty tree
    if (!tree_0.isEmpty()){
        check += 1;
    };

    // Test insert int
    tree_0.insert(10);
    tree_0.insert(-5);
    tree_0.insert(15);
    tree_0.insert(7);
    tree_0.insert(-12);

    if (tree_0.size() != 5){
        check += 1;
    };

    // Test insert string
    tree_1.insert("b");
    tree_1.insert("f");
    tree_1.insert("d");
    tree_1.insert(".");
    tree_1.insert(",");

    if (tree_1.size() != 5){
        check += 1;
    };

    // Test insert double
    tree_2.insert(1.21);
    tree_2.insert(2.1);
    tree_2.insert(12.3);
    tree_2.insert(0.55);
    tree_2.insert(1.7);

    if (tree_2.size() != 5){
        check += 1;
    };

    // Test insert same values
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);
    tree_3.insert(0);

    if (tree_3.size() != 5){
        check += 1;
    };

    // Test isEmpty on a tree with values
    if (tree_0.isEmpty()){
        check += 1;
    };

    // Test copy constructor
    RBTree<int> tree_5(tree_0);
    if (tree_5.size() != 5){
        check += 1;
    };
    
    // Test = operator overloading
    tree_4 = tree_0;
    if (tree_4.size() != 5){
        check += 1;
    };

    // Test remove
    tree_3.remove(0);
    if (tree_3.size() != 4){
        check += 1;
    };

    // Test search
    if (tree_0.search(10)->value() != 10){
        check += 1;
    };

    // Test treeMin
    if (tree_0.treeMin()->value() != -12){
        check += 1;
    }

    // Test treeMax
    if (tree_0.treeMax()->value() != 15){
        check += 1;
    }

    // Test exception handling for value not in tree
    try {
        tree_0.remove(99); // Attempt to remove a non-existent value
        check += 1;
    } catch (const value_not_in_tree_exception& e) {
        // Expected exception for removing a non-existent value
    } catch (...) {
        check += 1;
    }

    // Capture output using ostringstream
    ostringstream ossPreOrder, ossInOrder, ossPostOrder;
    streambuf* originalCoutBuffer = cout.rdbuf();

    // Capture Pre-order traversal
    cout.rdbuf(ossPreOrder.rdbuf());
    tree_0.printPreOrderTraversal();
    // Capture In-order traversal
    cout.rdbuf(ossInOrder.rdbuf());
    tree_0.printInOrderTraversal();
    // Capture Post-order traversal
     cout.rdbuf(ossPostOrder.rdbuf());
    tree_0.printPostOrderTraversal();

    // Restore original cout buffer
    cout.rdbuf(originalCoutBuffer);

    // Test printPreOrderTraversal
    string captured_preorder = ossPreOrder.str();
    if (captured_preorder != "10 -5 -12 7 15 "){
        check += 1;
    };
    // Test printInOrderTraversal
    string captured_inorder = ossInOrder.str();
    if (captured_inorder != "-12 -5 7 10 15 "){
        check += 1;
    };
    // Test printPostOrderTraversal
    string captured_postorder = ossPostOrder.str();
    if (captured_postorder != "-12 7 -5 15 10 "){
        check += 1;
    };
    
    return check;
};


int main()
{
    cout << "Testing BST class:" << endl;
    if (BST_sanity_check() != 0) {
        cout << BST_sanity_check() << "test cases failed." << endl;
    } else {
        cout << "All test cases passed (" << BST_sanity_check() << " cases)."<< endl;
    }

    cout << "Testing RBTree class:" << endl;
    if (RBT_sanity_check() != 0) {
        cout << RBT_sanity_check() << "test cases failed." << endl;
    } else {
        cout << "All test cases passed (" << RBT_sanity_check() << " cases)."<< endl;
    }

    return 0;
};