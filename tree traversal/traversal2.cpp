/* Binary Tree Traversal - Preorder, Inorder, Postorder */
#include <iostream>
#include <queue>
using namespace std;

struct Node {
	char		data;
	struct Node *	left;
	struct Node *	right;
};

// Function to visit node in Preorder
void Preorder(struct Node *root)
{
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if (root == NULL) {
		return;
	}

	cout << root->data<<endl; // Print data
	Preorder(root->left);
	Preorder(root->right);
}


// Funtion to visit node in inOrder
void Inorder(struct Node *root)
{
	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	cout << root->data<<endl; // Print data
	Inorder(root->right);
}


// Function to visit node in postOrder
void Postorder(struct Node *root)
{
	if (root == NULL) {
		return;
	}

	Postorder(root->left);
	Postorder(root->right);
	cout << root->data<<endl; // Print data
}


void Levelorder(struct Node *root)
{
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		Node *v = q.front();
		cout << v->data << " ";
		if (v->left != NULL) {
			q.push(v->left);
		}
		if (v->right != NULL) {
			q.push(v->right);
		}
		q.pop();
	}
}


// Function to insert a node in binary search Tree
Node *Insert(Node *root, char data)
{
	if (root == NULL) {
		root == new Node();
		root->data = data;
		root->left = root->right = NULL;
	}else if (data <= root->data) {
		root->left = Insert(root->left, data);
	} else{
		root->right = Insert(root->right, data);
	}
	return (root);
}


int main()
{
	// code to test the logic

	/*Creating an example tree
	 *                      M
	 *                     / \
	 *                    B   Q
	 *                   / \   \
	 *                  A   C   Z
	 */
	Node *root = NULL;

	root = Insert(root, 'M');
	root = Insert(root, 'B');
	root = Insert(root, 'Q');
	root = Insert(root, 'Z');
	root = Insert(root, 'A');
	root = Insert(root, 'C');
	// print the node in preOrder
	cout << "preoder: ";
	Preorder(root);
	cout << "\n";
	//Print Nodes in Inorder
	cout << "Inorder: ";
	Inorder(root);
	cout << "\n";
	//Print Nodes in Postorder
	cout << "Postorder: ";
	Postorder(root);
	cout << "\n";
	//Print nodes in levelOrder
	cout << "level order: ";
	Levelorder(root);
	cout << "\n";
	return (0);
}
