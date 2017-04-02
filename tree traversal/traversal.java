// java program for different tree traversal
//  class containing left and right chlld of current Node
// and key value
class Node {
	int key;
	Node left, right;
	public Node(int item)
	{
		key = item;
		left = right = null;
	}
}

class Traversal
{
	// Root of Binary tree
	Node root;
	Traversal()
	{
		root = null;
	}


	// Given a binary tree, print its nodes according to the "bottom-up"
	// post order traversal
	void printPostorder(Node node)
	{
		if (node == null) {
			return;
		}
		printPostorder(node.left);
		printPostorder(node.right);
		System.out.print(node.key + " ");
	}


	/* Given a binary tree, print its nodes in inorder*/
	void printInorder(Node node)
	{
		if (node == null) {
			return;
		}
		printInorder(node.left);
		System.out.print(node.key + " ");
		printInorder(node.right);
	}


	/* Given a binary tree, print its nodes in preorder*/
	void printPreorder(Node node)
	{
		if (node == null) {
			return;
		}
		System.out.print(node.key + " ");
		printPreorder(node.left);
		printPreorder(node.right);
	}


	// Wrapper over the above recursive functions
	void printPostorder() { printPostorder(root); }
	void printInorder() { printInorder(root); }
	void printPreorder() { printPreorder(root); }

	// Driver method
	public static void main(String[] args)
	{
		Traversal tree = new Traversal();

		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);

		System.out.println("Preorder traversal of binary tree is ");
		tree.printPreorder();

		System.out.println("\nInorder traversal of binary tree is ");
		tree.printInorder();

		System.out.println("\nPostorder traversal of binary tree is ");
		tree.printPostorder();
	}
}
