/*Red Black Tree
* C++
*/
#ifndef _RED_BLACK_TREE_HPP
#define _RED_BLACK_TREE_HPP // !_RED_BLACK_TREE_HPP

#include <iomanip>
#include <iostream>
using namespace std;

enum RBTColor {RED, BLACK};

template <class T>
class RBTNode {
public:
	RBTColor color;
	T key; //key value;
	RBTNode *left;
	RBTNode *right;
	RBTNode *parent;

	RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
		key(value), color(c), parent(), left(l), right(r) {}
};

template <class T>
class RBTree {
private:
	RBTNode<T> *mRoot; //root node;

public:
	RBTree();
	~RBTree();

	void preOrder();

	void inOrder();

	void postOrder();

	//recursively search for a node with key value key;
	RBTNode<T>* search(T key);
	//iteratively search
	RBTNode<T>* iterativeSearch(T key);

	//find minimum node:
	T minimum();
	//find maximun node:
	T maximum();

	//find the successor node of node x: 数值大于该节点的最小节点。
	RBTNode<T>* successor(RBTNode<T> *x);
	//find the predecessor node of node x:数值小于该节点的最大节点。
	RBTNode<T>* predecessor(RBTNode<T> *x);

	//insert
	void insert(T key);
	//delete
	void remove(T key);
	//destroy Tree
	void destroy();
	//print the Tree:
	void print();
private:
	void preOrder(RBTNode<T>* tree) const;
	void inOrder(RBTNode<T>* tree) const;
	void postOrder(RBTNode<T>* tree) const;

	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

	RBTNode<T>* minimum(RBTNode<T>* tree);
	RBTNode<T>* maximum(RBTNode<T>* tree);

	//左旋：
	void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
	//right rotate:
	void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
	//insert:
	void insert(RBTNode<T>* &root, RBTNode<T>* node);
	//insert fixup:
	void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
	//delete:
	void remove(RBTNode<T>* &root, RBTNode<T>* node);
	//delete fix up:
	void removeFixUp(RBTNode<T>* &root, RBTNode<T>* node, RBTNode<T>* parent);
	
	void destroy(RBTNode<T>* &tree);

	void print(RBTNode<T>* &tree, T key, int direction);

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)
#define rb_set_black(r) do {(r)->color = BLACK; } while(0)
#define rb_set_red(r) do {(r)->color = RED;} while(0)
#define rb_set_parent(r,p) do {(r)->parent = (p); } while(0)
#define rb_set_color(r,c) do {(r)->color = (c); } while(0)
};

/*
 * 构造函数
 */
template <class T>
RBTree<T>::RBTree() :mRoot(NULL) {}

/*
* 析构函数
*/

template <class T> 
RBTree<T>::~RBTree() {
	destroy();
}

/*
 * 前序遍历"红黑树"
*/
template <class T>
void RBTree<T>::preOrder(RBTNode<T>* tree) const
{
	if (tree != NULL) {
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
template <class T> 
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

/*
* 中序遍历"红黑树"
*/
/*The idea of const functions is not allow them to modify 
*the object on which they are called.
*It is recommended practice to make as many functions
*const as possible so that accidental changes to objects are avoided.
*/
template <class T>
void RBTree<T>::inOrder(RBTNode<T>* tree) const
{
	if (tree != NULL) {
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}
template <class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

/*
* 后序遍历"红黑树"
*/
template <class T>
void RBTree<T>::postOrder(RBTNode<T>* tree) const
{
	if (tree != NULL) {
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}
template <class T> 
void RBTree<T>::postOrder()
{
	postOrder(mRoot);
}

/*
* (递归实现)查找"红黑树x"中键值为key的节点 
*/
template <class T> 
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
	if (x == NULL || x->key == key) {
		return x;
	}
	if (x->key < key)
		return search(x->left, key);
	else
		return search(x->right, key);
}
template <class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);
}

/*
 * (非递归实现)查找"红黑树x"中键值为key的节点
*/
template <class T> 
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	while ((x != NULL) && (x->key != key)) {
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}
template <class T> 
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

/*
* 查找最小结点：返回tree为根结点的红黑树的最小结点。
*/
template <class T> 
RBTNode<T>* RBTree<T>::minimum(RBTree<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}

template <class T> 
T RBTree<T>::minimum()
{
	RBTNode<T>* p = minimum(mRoot);
	if (p!= NULL)
		return p->key;
	return (T)NULL;
}

/*
* 查找最大结点：返回tree为根结点的红黑树的最大结点。
*/
template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}
template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T>* p = maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

/*
* 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
*/
template <class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x)
{
	//if x has right child, then the successor of x is the smallest node in the right subtree of x;
	if (x->right != NULL)
		return minimum(x->right);
	// if x does not have a right child, there are two cases:
	// 1. x is a left child, so the successor of x is his parent;
	// 2. x is a right child, so search for the lowest parent of x that has left child. this lowest parent is the successor;
	RBTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->right)) {
		x = y;
		y = y->parent;
	}
	return y;
}

/*
* 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
*/
template <class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x)
{
	// if the x has left child, so the predecessor is the greatest node in the left subtree;
	if (x->left != NULL)
		return maximum(x->left);
	// if x has no left child, and there are two cases;
	// (01) x is a right child, so the predecessor is his parent.
	// (02) x is a left child, so search the lowest the parent of x that has the left child, this lowest parent is the predecessor.
	RBTNode<T>* y = x->parent;
	while ((y != NULL) && (x == y->left)) {
		x = y;
		y = y->parent;
	}
	return y;
}

/*
* 对红黑树的节点(x)进行左旋转
*
* 左旋示意图(对节点x进行左旋)：
*      px                              px
*     /                               /
*    x                               y
*   /  \      --(左旋)-->           / \                #
*  lx   y                          x  ry
*     /   \                       /  \
*    ly   ry                     lx  ly
*
*
*/
template<class T>
void RBTree<T>::leftRotate(RBTNode<T>* &root, RBTNode<T>* x)
{
	//the right child is y:
	RBTNode<T> *y = x->right;

	//set the "ly" to right child of x:
	// if the left child of y is not null, set x as its parent;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;

	//set x's parent as y's parent:
	y->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else
	{
		if (x->parent->left == x) {
			x->parent->left = y; // if x is the left child of his parent, set y as the parent's left child
		}
		else {
			x->parent->right = y;
		}
	}
	y->left = x;
	x->parent = y;
}

/*
* 对红黑树的节点(y)进行右旋转
*
* 右旋示意图(对节点y进行右旋)：
*            py                               py
*           /                                /
*          y                                x
*         /  \      --(右旋)-->            /  \                     #
*        x   ry                           lx   y
*       / \                                   / \                   #
*      lx  rx                                rx  ry
*
*/
template <class T>
void RBTree<T>::rightRotate(RBTNode<T>* &root, RBTNode<T>* y)
{
	RBTNode<T> *x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;
	//set y's parent to x's parent;
	x->parent = y->parent;

	if (y->parent == NULL) {
		root = x;
	}
	else {
		if (y->parent->right == y)
			y->parent->right = x;
		else
			y->parent->left = x;
	}

	x->right = y;
	y->parent = x;
}

/*
* 将结点插入到红黑树中
*
* 参数说明：
*     root 红黑树的根结点
*     node 插入的结点        // 对应《算法导论》中的node
*/
template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T> node)
{
	RBTNode<T>* y = NULL;
	RBTNode<T>* x = root;
	//1. insert as a binary search tree.
	while (x != NULL) {
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y != NULL) {
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;

	// 2. set the node color to red;
	node->color = RED;
	// 3. fix up 
	insertFixUp(root, node);
}
/*
* 将结点(key为节点键值)插入到红黑树中
*
* 参数说明：
*     tree 红黑树的根结点
*     key 插入结点的键值
*/
template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T>* z = NULL;
	// if can not create the node return
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;
	insert(mRoot, z);
}

/*
* 红黑树插入修正函数
*
* 在向红黑树中插入节点之后(失去平衡)，再调用该函数；
* 目的是将它重新塑造成一颗红黑树。
*
* 参数说明：
*     root 红黑树的根
*     node 插入的结点        // 对应《算法导论》中的z
*/

template <class T>
void RBTree<T>::insertFixUp(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent;
	//if parent exists and parent is RED;
	While((parent = rb_parent(node)) && rb_is_red(parent)) {
		gparent = rb_parent(parent);

		//if parent is the left child of grandparent;
		if (parent == gparent->left) {
			// case1 : uncle is RED
			RBTNode<T> *uncle = gparent->right;
			if (uncle && rb_is_red(uncle)) {
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = parent;
				continue;
			}

			//Case2: uncle is black, and node is the right child;
			if (parent->left == node) {
				RBTNode<T>* tmp;
				leftRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			//Case3: uncle is black, and node is left child.
			rb_set_black(parent);
			rb_set_red(gparent);
			rightRotate(root, gparent);
		}
		else { // if parent is the right child of the grand parent;
			RBTNode<T>* uncle = gparent->left;
			// Case1: uncle is RED;
			if (uncle && rb_is_red(uncle)) {
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}

			//Case2: uncle is BLACK, the node is left child;
			if (parent->left == node) {
				RBTNode<T>* tmp;
				rightRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			//Case3: uncle is BLACK, the node is right child;
			rb_set_black(parent);
			rb_set_red(gparent);
			leftRotate(root, parent);

		}
	}
	rb_set_black(root);
}
/*
* 删除结点(node)，并返回被删除的结点
*
* 参数说明：
*     root 红黑树的根结点
*     node 删除的结点
*/
template <class T>
void RBTree<T>::remove(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T>* child, *parent;
	RBTColor color;

	// the deleted node has left and right child;
	if ((node->left != NULL) && (node->right != NULL)) {
		//sucessor of the deleting node.(replace node)
		// use replace node to replace the deleted node; and remove the deleted node;
		RBTNode<T>* replace = node;
		// get the successor of the node;
		replace = replace->right;
		while (replace->left != NULL) 
			replace = replace->left;

		// if node is not root; root has no parent;
		if (rb_parent(node)) {
			if (rb_parent(node)->left == node)
				rb_parent(node)->left = replace;
			else
				rb_parent(node)->right = replace;
		}
		else // node is root;
			root = replace;
		//child is the right child of the replace node;
		//since the replace node must has no left child;
		child = replace->right;
		parent = rb_parent(replace);
		//store the color of the replace node;
		color = rb_color(replace);

		// if node is parent of replace node;
		if (parent == node) {
			parent = replace;
		}
		else {
			// if child is not null;
			if (child)
				rb_set_parent(child, parent);
			parent->left = child;

			replace->right = node->right;
			rb_set_parent(node->right, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;
		if (color == BLACK) {
			removeFixUp(root, child, parent);
		}
		delete node;
		return;
	}
	//if deleted node has no left child or no right child;
	if (node->left != NULL)
		child = node->left;
	else
		child = node->right;
	parent = node->parent;
	// store the node color;
	color = node->color;

	if (child)
		child->parent = parent;

	//if node is not root;
	if (parent) {
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else {
		root = child;
	}

	if (color == BLACK)
		removeFixUp(root, child, parent);
	delete node;
}
/*
* 删除红黑树中键值为key的节点
*
* 参数说明：
*     tree 红黑树的根结点
*/
template <class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T>* node;
	//search for the node with key;
	if (node = search(mRoot, key) != NULL)
		remove(mRoot, node);
}

/*
* 红黑树删除修正函数
*
* 在从红黑树中删除插入节点之后(红黑树失去平衡)，再调用该函数；
* 目的是将它重新塑造成一颗红黑树。
*
* 参数说明：
*     root 红黑树的根
*     node 待修正的节点
*/
template <class T>
void RBTree<T>::removeFixUp(RBTree<T>* &root, RBTree<T>* node, RBTree<T>* parent) {
	RBTNode<T>* other;

	while ((!node || rb_is_black(node)) && node != root) {
		if (parent->left == node)
		{
			other = parent->right;
			//Case1 :x 's brother is RED;
			if (rb_is_red(other)) {
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			// Case2: x's brother w is BLACK, and both child of w is BLACK;
			if ((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_black(other->right)))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else {
				// Case3 : x 's brother is BLACK, and w's left child is RED, right child is BLACK;
				if (!other->right || rb_is_black(other->right)) {
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				//Case4 :x's brother w is BLACK, and w 's right child is RED, left child whatever color it is;
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->right);
				leftRotate(root, parent);
				node = root;
				break;
			}
		}
		else {
			other = parent->left;
			// Case1 :x's brother is RED;
			if (rb_is_red(other)) {
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			//Case2:  x's brother w is BLACK, and both of w's children are BLACK;
			if ((!other->left || rb_is_black(other->left)) && (!other->right || rb_is_black(other->right))) {
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else {
				// Case3 : x 's brother is BLACK, and w's left child is BLACK, right child is RED;
				if (!other->left || rb_is_black(other->left)) 
				{
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				//Case4 : x's brother w is BLACK, and w 's right child is RED, left child is whatever color;
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->left);
				rightRotate(other->left);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}

/*
* 销毁红黑树
*/
template <class T> 
void RBTree<T>::destroy(RBTNode<T>* &tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}
template <class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

/*
* 打印"二叉查找树"
*
* key        -- 节点的键值
* direction  --  0，表示该节点是根节点;
*               -1，表示该节点是它的父结点的左孩子;
*                1，表示该节点是它的父结点的右孩子。
*/
template <class T> 
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0) // tree is root;
			cout << setw(2) << tree->key << "(B) is root" << endl;
		else
			cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << "is" << setw(2) << key << "'s" << set(12)
			(direction == 1 ? "right child" : "leftchild") << endl;
		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}
template <class T> 
void RBTree<T>::print()
{
	print(mRoot, mRoot->key, 0);
}

#endif