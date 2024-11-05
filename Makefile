all: mytests

mytests: mytests.o BST.o BSTNode.o
	g++ -o mytests BST.o BSTNode.o mytests.o
	./mytests

mytests.o: mytests.cpp
	g++ -c mytests.cpp

BST.o: BST.cpp BST.hpp
	g++ -c BST.cpp

BSTNode.o: BSTNode.cpp BSTNode.hpp
	g++ -c BSTNode.cpp



