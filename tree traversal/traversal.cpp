#include <iostream>
#include <queue>
using namespace std;

// Node class
class Node
{
	string key;
	Node *left;
	Node *right;
public:
	Node()
	{
		key = -1;
		left = NULL;
		right = NULL;
	}


	void setKey(string aKey)
	{
		key = aKey;
	}


	void setLeft(Node *aLeft)
	{
		left = aLeft;
	}


	void setRight(Node *aRight)
	{
		right = aRight;
	}


	string Key() { return (key); }
	Node *Left() { return (left); }
	Node *Right() { return (right); }
};

// Tree class
class Tree {
	Node *root;
public:
	Tree();
	~Tree();
	Node *Root() { return (root); }
	void addNode(string key);
	void levelOrder(Node *n);
	void inOrder(Node *);
	void postOrder(Node *);
	void preOrder(Node *node);

private:
	void addNode(string key, Node *leaf);
	void freeNode(Node *leaf);
};

// Constructor
Tree::Tree()
{
	root = NULL;
}


// Destructor
Tree::~Tree()
{
	freeNode(root);
}


// Free the Node
void Tree::freeNode(Node *leaf)
{
	if (leaf != NULL) {
		freeNode(leaf->Left());
		freeNode(leaf->Right());
		delete leaf;
	}
}


// Add a Node
void Tree::addNode(string key)
{
	// No elements, Add the root
	if (root == NULL) {
		cout << "add root node ..." << key << endl;
		Node *n = new Node();
		n->setKey(key);
		root = n;
	}else {
		cout << "add other node ..." << key << endl;
		addNode(key, root);
	}
}


// Add a node(private)
void Tree::addNode(string key, Node *leaf)
{
	if (key <= leaf->Key()) {
		if (leaf->Left() != NULL) {
			addNode(key, leaf->Left());
		} else{
			Node *n = new Node();
			n->setKey(key);
			leaf->setLeft(n);
		}
	}else {
		if (leaf->Right() != NULL) {
			addNode(key, leaf->Right());
		} else{
			Node *n = new Node();
			n->setKey(key);
			leaf->setRight(n);
		}
	}
}


// Print the tree level-order assisted by queue
void Tree::levelOrder(Node *n)
{
	// create a queue
	queue<Node *> q;
	// push the root;
	q.push(n);

	while (!q.empty())
	{
		// Dequeue a node front
		Node *v = q.front();
		cout << v->Key() << " ";
		// Enqueue the left children
		if (v->Left() != NULL) {
			q.push(v->Left());
		}
		// Enqueue the right children
		if (v->Right() != NULL) {
			q.push(v->Right());
		}

		// Pop the visited node
		q.pop();
	}
}


void Tree::preOrder(Node *node)
{
	if (node) {
		cout << node->Key() << " ";
		preOrder(node->Left());
		preOrder(node->Right());
	}
}


void Tree::inOrder(Node *Root)
{
	if (Root != NULL) {
		inOrder(Root->Left());
		cout << Root->Key() << " ";
		inOrder(Root->Right());
	}
}


void Tree::postOrder(Node *Root)
{
	if (Root != NULL) {
		postOrder(Root->Left());
		postOrder(Root->Right());
		cout << Root->Key() << " ";
	}
}


// Test main program
int main()
{
	Tree *tree = new Tree();

	tree->addNode("F");
	tree->addNode("C");
	tree->addNode("A");
	tree->addNode("H");
	tree->addNode("G");
	tree->addNode("I");
	tree->addNode("Z");

	cout << "level order traversal" << endl;
	tree->levelOrder(tree->Root());
	cout << endl;

	cout << "Pre order traversal" << endl;
	tree->preOrder(tree->Root());
	cout << endl;

	cout << "In order traversal" << endl;
	tree->inOrder(tree->Root());
	cout << endl;

	cout << "Post order traversal" << endl;
	tree->postOrder(tree->Root());
	cout << endl;

	delete tree;
	return (0);
}
