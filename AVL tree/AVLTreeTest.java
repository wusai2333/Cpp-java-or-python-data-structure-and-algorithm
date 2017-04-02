//
// Java Program to implement AVL tree
//
import java.util.Scanner;
// Class AVL Node
class AVLNode
{
	AVLNode left, right;
	int data;
	int height;

	// Constructor
	public AVLNode()
	{
		left = null;
		right = null;
		data = 0;
		height = 0;
	}


	// Constructor
	public AVLNode(int n)
	{
		left = null;
		right = null;
		data = n;
		height = 0;
	}
}

// class AVLTree
class AVLTree
{
	private AVLNode root;

	// Constructor
	public AVLTree()
	{
		root = null;
	}


	// Function to check if tree is Empty
	public boolean isEmpty()
	{
		return (root == null);
	}


	// Make the tree logically Empty
	public void makeEmpty()
	{
		root = null;
	}


	// Function to insert data
	public void insert(int data)
	{
		root = insert(data, root);
	}


	// Function to get height of the Node
	private int height(AVLNode t)
	{
		return (t == null ? -1 : t.height);
	}


	// Function to max left / right node
	private int max(int lhs, int rhs)
	{
		return (lhs > rhs ? lhs : rhs);
	}


	// Function to insert data recursively
	private AVLNode insert(int x, AVLNode t)
	{
		if (t == null) {
			t = new AVLNode(x);
		} else if (x < t.data) {
			t.left = insert(x, t.left);
			if (height(t.left) - height(t.right) == 2) {
				if (x < t.left.data) {
					t = rotateWithLeftChild(t);
				} else{
					t = rotateWithRightChild(t);
				}
			}
		}else if (x > t.data) {
			t.right = insert(x, t.right);
			if (height(t.right) - height(t.left) == 2) {
				if (x > t.right.data) {
					t = rotateWithRightChild(t);
				} else{
					t = rotateWithLeftChild(t);
				}
			}
		}else {
			// Duplicate do nothing
		}
		t.height = max(height(t.left), height(t.right)) + 1;
		return (t);
	}


	// Rotate binary node with Left Child
	private AVLNode rotateWithLeftChild(AVLNode k2)
	{
		AVLNode k1 = k2.left;

		k2.left = k1.right;
		k1.right = k2;
		k2.height = max(height(k2.left), height(k2.right)) + 1;
		k1.height = max(height(k1.left), height(k1.right)) + 1;
		return (k1);
	}


	// Rotate binary tree with right child
	private AVLNode rotateWithRightChild(AVLNode k1)
	{
		AVLNode k2 = k1.right;

		k1.right = k2.left;
		k2.left = k1;
		k1.height = max(height(k1.left), height(k1.right)) + 1;
		k2.height = max(height(k2.left), height(k2.right)) + 1;
		return (k2);
	}


	/* Double rotate binary tree node: first left Child
	 * with its right child; then node k3 with new left child*/
	private AVLNode doubleWithLeftChild(AVLNode k3)
	{
		k3.left = rotateWithRightChild(k3.left);
		return (rotateWithLeftChild(k3));
	}


	/* Double rotate binary tree node: first right child
	 * with its left child; the node k1 with new right child*/
	private AVLNode doubleWithRightChild(AVLNode k1)
	{
		k1.right = rotateWithLeftChild(k1.right);
		return (rotateWithRightChild(k1));
	}


	// Functions to count number of nodes
	public int countNodes()
	{
		return (countNodes(root));
	}


	private int countNodes(AVLNode r)
	{
		if (r == null) {
			return (0);
		} else{
			int l = 1;
			l += countNodes(r.left);
			l += countNodes(r.right);
			return (l);
		}
	}


	// Function to search for an element
	public boolean search(int val)
	{
		return (search(root, val));
	}


	private boolean search(AVLNode r, int val)
	{
		boolean found = false;

		while (r != null&& !found)
		{
			int rval = r.data;
			if (val < rval) {
				r = r.left;
			} else if (val > rval) {
				r = r.right;
			} else{
				found = true;
				break;
			}
		}
		return (found);
	}


	// Function for inorder traversal
	public void inorder()
	{
		inorder(root);
	}


	private void inorder(AVLNode r)
	{
		if (r != null) {
			inorder(r.left);
			System.out.print(r.data + " ");
			inorder(r.right);
		}
	}


	// Function for preorder traversal
	public void preorder()
	{
		preorder(root);
	}


	private void preorder(AVLNode r)
	{
		if (r != null) {
			System.out.print(r.data + " ");
			preorder(r.left);
			preorder(r.right);
		}
	}


	// Function for postorder traversal
	public void postorder()
	{
		postorder(root);
	}


	private void postorder(AVLNode r)
	{
		if (r != null) {
			postorder(r.left);
			postorder(r.right);
			System.out.print(r.data + " ");
		}
	}
}

public class AVLTreeTest
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		// Creating objevt of AVLTree
		AVLTree avlt = new AVLTree();

		System.out.println("AVLTree Test\n");
		char ch;
		// Perform tree operations
		do
		{
			System.out.println("\nAVLTree Operations\n");
			System.out.println("1. insert");
			System.out.println("2. search");
			System.out.println("3. count nodes");
			System.out.println("4. check empty");
			System.out.println("5. clear tree");

			int choice = scan.nextInt();
			switch (choice)
			{
			case 1:
				System.out.println("Enter integer element to insert");
				avlt.insert(scan.nextInt());
				break;

			case 2:
				System.out.println("Enter integer to search");
				System.out.println("Search result: " + avlt.search(scan.nextInt()));
				break;

			case 3:
				System.out.println("Nodes = "+ avlt.countNodes());
				break;

			case 4:
				System.out.println("Empty status = "+ avlt.isEmpty());
				break;

			case 5:
				System.out.println("\nTree Cleared");
				avlt.makeEmpty();
				break;

			default:
				System.out.println("Wrong Entry\n");
				break;
			}
			// Display tree
			System.out.print("\nPost order: ");
			avlt.postorder();
			System.out.print("\nIn order: ");
			avlt.inorder();
			System.out.print("\nPre order: ");
			avlt.preorder();

			System.out.println("\nDo you want to continue (Type y or n)");
			ch = scan.next().charAt(0);
		} while (ch == 'Y' || ch == 'y');
	}
}
