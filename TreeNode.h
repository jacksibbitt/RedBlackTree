//Honor Pledge:
//
// I pledge that I have neither given nor 
// recieved any help on this assignment.
//
//jsibbitt
enum Color {None, Red, Black};


class TreeNode
{
	public:
		TreeNode();
		TreeNode(int data);
		~TreeNode();
		void setParent(TreeNode * parent);
		void setLeftChild(TreeNode * leftChild);
		void setRightChild(TreeNode * rightChild);
		int getData();
		
		TreeNode * getLeftChild();
		TreeNode * getRightChild();
		TreeNode * getParent();
		
		void setRed();
		void setBlack();
		void setColor(Color color);
		Color getColor();
		
	private:
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		TreeNode * parent_;
		int data_;
		Color color_;
		
};