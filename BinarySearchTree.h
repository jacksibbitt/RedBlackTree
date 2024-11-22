//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include "TreeNode.h"
#include <iostream>

class BinarySearchTree
{
	public:
		BinarySearchTree();
		~BinarySearchTree();
		TreeNode * getRoot();
		void insert (int value);
		void printTree(TreeNode * root);
		int getHeight(TreeNode * root);
		
	private: 
		
		TreeNode * root_;
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		
	protected:
		void setRoot(TreeNode * root);
		
};