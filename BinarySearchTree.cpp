//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root_(nullptr)
{
	
}

BinarySearchTree::~BinarySearchTree()
{
	if(root_ != nullptr)
	{
		delete root_;
	}
	
}

TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

void BinarySearchTree::insert(int value)
{
	TreeNode * node = new TreeNode(value);
	
	root_ = insertNode(root_, node);
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * newNode)
{
	if(root == nullptr)
	{
		return newNode;
	}
	else
	{
		if(newNode->getData() < root->getData())
		{
			//left subtree
			root->setLeftChild(insertNode(root->getLeftChild(), newNode));
			root->getLeftChild()->setParent(root);
		}
		else
		{
			//right subtree
			root->setRightChild(insertNode(root->getRightChild(), newNode));
			root->getRightChild()->setParent(root);
		}
		
		
		return root;
	}
}

void BinarySearchTree::printTree(TreeNode * root)
{
	
	//in order traversal 
	if(root == nullptr)
	{
		return;
	}
	else
	{
		printTree(root->getLeftChild());
	
		std::cout << root->getData() << " ";
	
		printTree(root->getRightChild());
		
	}
	
	
	
}

int BinarySearchTree::getHeight(TreeNode * root)
{
	if(root == nullptr)
	{
		return 0;
	}
	else
	{
		//find the height of each subtree. This is recursive meaning we go through all potential subtrees.
		int leftSubHeight = getHeight(root->getLeftChild());
		int rightSubHeight = getHeight(root->getRightChild());
		
		//need the maximum height of subtrees so we can find the total height.
		return std::max(leftSubHeight, rightSubHeight) +1;
	}
	
}

void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}