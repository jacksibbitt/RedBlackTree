//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
#include "Node.h"

Node::Node(int data)
{
	data_=data;
}

void Node::setData(int data)
{
	data_ = data;
}

int Node::getData()
{
	return data_;
}