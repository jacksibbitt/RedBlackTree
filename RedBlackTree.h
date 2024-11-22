//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include "BinarySearchTree.h"
#include <iostream>

class RedBlackTree : public BinarySearchTree
{
	public:
		RedBlackTree();
		virtual ~RedBlackTree();
		virtual void insert(int data);
		void printTree(TreeNode * root);
		void printBlackNodes(TreeNode * root);
		void printRedNodes(TreeNode * root);
		
		
	private: 
		virtual TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
		
		
};