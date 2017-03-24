/**
* C++ ����: ���������
*
* @author skywang
* @date 2013/11/07
*/

#include <iostream>
#include "RBtree.h"

using namespace std;

int main() {
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	int check_insert = 0; // ���붯���ļ�鿪�� ��0�� �رգ� 1�� �򿪣�
	int check_remove = 0; // ɾ�������ļ�鿪�� ��0�� �رգ� 1�� �򿪣�
	int ilen = sizeof(a) / sizeof(a[0]);
	RBTree<int>* tree = new RBTree<int>();

	cout << "== original value: ";
	for (int i = 0; i < ilen; i++) {
		tree->insert(a[i]);
		// set check_insert = 1 , test the insert function;
		if (check_insert) {
			cout << " == insert node: " << a[i] << endl;
			cout << " == tree info: " << endl;
			tree->print();
			cout << endl;
		}
	}

	cout << "== preOrder traverse: ";
	tree->preOrder();

	cout << "\n== inOrder traverse: ";
	tree->inOrder();

	cout << "\n== postOrder traverse: ";
	tree->postOrder();
	cout << endl;

	cout << "== the minimum: " << tree->minimum() << endl;
	cout << "== the maximum: " << tree->maximum() << endl;
	cout << "== tree info: " << endl;
	tree->print();
	//set the check_remove value to test the "remove function"
	if (check_remove)
	{
		for (int i = 0; i < ilen; i++) {
			tree->remove(a[i]);

			cout << "== delete node: " << a[i] << endl;
			cout << "== tree info: " << endl;
			tree->print();
			cout << endl;
		}
	}

	// destroy the red black tree;
	tree->destroy();

	return 0;

}