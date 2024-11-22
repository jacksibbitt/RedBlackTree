//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include "TreeNode.h"

TreeNode::TreeNode() : data_(0), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr)
{
	color_ = Red;
}

TreeNode::TreeNode(int data) : data_(0), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr)
{
	data_ = data;
}

TreeNode::~TreeNode()
{
	if(leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	if(rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}

void TreeNode::setLeftChild(TreeNode * leftChild)
{
	leftChild_ = leftChild;
}

void TreeNode::setRightChild(TreeNode * rightChild)
{
	rightChild_ = rightChild;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}


int TreeNode::getData()
{
	return data_;
}

void TreeNode::setRed()
{
	color_ = Red;
}

void TreeNode::setBlack()
{
	color_ = Black;
}

Color TreeNode::getColor()
{
	return color_;
}

void TreeNode::setColor(Color color)
{
	color_ = color;
}