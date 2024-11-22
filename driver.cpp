//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include <iostream>
#include <fstream>
#include "RedBlackTree.h"

int main()
{
	RedBlackTree * myTree = new RedBlackTree();
	
	
	
	//phase 1 and 2
	
	std::ifstream insertFile;
	
	insertFile.open("data.txt");
	
	if(insertFile.is_open()) // makes sure file actually exists
	{
		int tempNum = 0;
		insertFile >> tempNum;
		myTree->insert(tempNum);
		
		while(insertFile >> tempNum)
		{
			myTree->insert(tempNum);
			
		}
		std::cout << std::endl;
	}
	
	insertFile.close();
	
	
	myTree->printTree(myTree->getRoot());
	std::cout << std::endl;
	
	//phase 5
	std::cout << "Black Nodes: ";
	myTree->printBlackNodes(myTree->getRoot());
	std::cout << std::endl;
	
	std::cout << "Red Nodes: ";
	myTree->printRedNodes(myTree->getRoot());
	std::cout << std::endl;
	
	std::cout << "root: " << myTree->getRoot()->getData() << std::endl;
	std::cout << "Height: " << myTree->getHeight(myTree->getRoot()) << std::endl;
	
	delete myTree;
	
	return 0;
}

