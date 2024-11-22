//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	
}

RedBlackTree::~RedBlackTree()
{
	if(getRoot() != nullptr)
	{
		delete getRoot();
	}
	
}

void RedBlackTree::insert(int data)
{
	TreeNode * node = new TreeNode(data);
	if(getRoot() == nullptr)
	{
		node->setBlack();
	}
	else
	{
		node->setRed();
	}
	
	setRoot(insertNode(getRoot(), node));

	TreeNode * root = getRoot();
	
	balanceColor(root, node);
}

TreeNode * RedBlackTree::insertNode(TreeNode * root, TreeNode * newNode)
{
	//same as a BST, just gets sorted later. 
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

void RedBlackTree::printTree(TreeNode * root)
{
	
	
	//in order traversal 
	if(root == nullptr)
	{
		return;
	}
	else
	{
		printTree(root->getLeftChild());
		
		Color color = root->getColor();
		std::string letter = "";
		
		if(color == Red)
		{
			letter = "R"; 
		}
		else if(color == Black)
		{
			letter = "B";
		}
		else
		{
			letter = "na";
		}
		
	
		std::cout << "(" << letter << ") ";
	
		std::cout << root->getData() << " ";
	
		printTree(root->getRightChild());
		
	}
	
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	//move up the left child to the new right child position
	TreeNode * RightChild = newNode->getRightChild();
	newNode->setRightChild(RightChild->getLeftChild());
	if(newNode->getRightChild() != nullptr)
	{
		newNode->getRightChild()->setParent(newNode);
	}
	
	//get ready to move right child to above newNode
	RightChild->setParent(newNode->getParent());
	
	//if we are at the root.
	if(newNode->getParent() == nullptr)
	{
		root = RightChild;
		setRoot(RightChild);
	}
	else if(newNode == newNode->getParent()->getLeftChild()) // if newNode is on the left
	{
		newNode->getParent()->setLeftChild(RightChild); // we now set the parent's left child to RightChild so that it takes the place of newNode
		
	}
	else // if newNode is on the right
	{
		newNode->getParent()->setRightChild(RightChild);
	}

	RightChild->setLeftChild(newNode); // newNode can now be set to RightChilds left child and we can set newNodes parent to RightChild
	newNode->setParent(RightChild);
	
	//at the end of this, newNode is now the child of it's old right child
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
					
	TreeNode * LeftChild = newNode->getLeftChild();
	newNode->setLeftChild(LeftChild->getRightChild());
	if(newNode->getLeftChild() != nullptr)
	{
		newNode->getLeftChild()->setParent(newNode);
	}
	LeftChild->setParent(newNode->getParent());
	
	//if we are at the root.
	if(newNode->getParent() == nullptr)
	{
		root = LeftChild;
		setRoot(LeftChild);
	}
	else if(newNode == newNode->getParent()->getLeftChild())
	{
		newNode->getParent()->setLeftChild(LeftChild);
		
	}
	else
	{
		newNode->getParent()->setRightChild(LeftChild);
	}

	LeftChild->setRightChild(newNode);
	
	newNode->setParent(LeftChild);
	//left child is now in newNode' old position. has the same parent as newNode used to have. newNode is now the right child of LeftChild
	
	
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	//will need these in order to do rotates.
	TreeNode * ParentNode = new TreeNode();
	TreeNode * GrandParentNode = new TreeNode();
	
	//will run until all rules are met. 
	while((newNode != root)&&(newNode->getColor()== Red)&& (newNode->getParent()->getColor() == Red))
	{
		ParentNode = newNode->getParent();
		GrandParentNode = ParentNode->getParent();
		
		//if this is the case, that means the right child is the uncle (if it exists). opposite for the else. 
		if(ParentNode == GrandParentNode->getLeftChild())
		{
			TreeNode * UncleNode = GrandParentNode->getRightChild();
			
			//if the uncle node is red, it means we can set the grand parent node to red and change both parent and uncle to black. 
			if((UncleNode != nullptr) && (UncleNode->getColor() == Red))
			{
				GrandParentNode->setRed();
				ParentNode->setBlack();
				UncleNode->setBlack();
				//we may still need to check the grandparent node to make sure its parent isnt red. This sets GrandParentNode to newNode so that when the while goes through again we check the grandparent. 
				newNode = GrandParentNode;
			}
			else
			{
				//if the uncle doesnt exist or is black, we need to do a rotate based on the side that newNode is on.
				if (newNode == ParentNode->getRightChild())
				{
					rotateLeft(root, ParentNode); // rotates the ParentNode w/ newNode
					newNode = ParentNode; // will check the parent of where newNode USED TO BE!!! (so it's old child) it's parent should be the same, and now will check the parent. 
					ParentNode = newNode->getParent();
				}
				else
				{

					rotateRight(root, GrandParentNode);	//rotates the GrandParent with it's left child (ParentNode). Will then swap their colors
					Color temp = ParentNode->getColor();
					ParentNode->setColor(GrandParentNode->getColor());
					GrandParentNode->setColor(temp);
					newNode = ParentNode; // checks ParentNode 
					
				}
			}
		}
		else
		{
			//in this case, we basically can just do the opposite of what the first case is since the node is on the other side. 
			TreeNode * UncleNode = GrandParentNode->getLeftChild();
			if((UncleNode != nullptr) && (UncleNode->getColor() == Red))
			{
				GrandParentNode->setRed();
				ParentNode->setBlack();
				UncleNode->setBlack();
				newNode = GrandParentNode;
				
			}
			else
			{
				if(newNode == ParentNode->getLeftChild())
				{
					rotateRight(root, ParentNode);
					newNode = ParentNode;
					ParentNode = newNode->getParent();
				}
				else
				{
					rotateLeft(root, GrandParentNode);
					Color temp = ParentNode->getColor();
					ParentNode->setColor(GrandParentNode->getColor());
					GrandParentNode->setColor(temp);
					newNode = ParentNode;
					 
				}
			}
		}
	}
	root->setBlack();
}

//for rotates and stuff look at slides 38-40 on lecture 21
//frmo within the insertNode method we need to invoke balanceColor to ensure that all of the properties of a Red-Black tree are upheld.
//ALWAYS TRY TO RECOLOR FIRST (if you can simply recolor a node frmo red to black, then you gotta start doing rotates and recolors after rotates)
// dont need to rotate unless height is unbalanced / two reds in a row.

void RedBlackTree::printRedNodes(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		//inorder
		printRedNodes(root->getLeftChild());
		if (root->getColor() == Red)
		{
			std::cout << root->getData() << " ";
		}
		printRedNodes(root->getRightChild());
	}
}

void RedBlackTree::printBlackNodes(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		//preorder
		if (root->getColor() == Black)
		{
			std::cout << root->getData() << " ";
		}
		printBlackNodes(root->getLeftChild());
		printBlackNodes(root->getRightChild());
	}
}