all: mytests

mytests: mytests.o
	g++ -o mytests mytests.o
	./mytests

mytests.o: mytests.cpp BSTNode.hpp BST.hpp RBTreeNode.hpp RBTree.hpp
	g++ -c mytests.cpp

