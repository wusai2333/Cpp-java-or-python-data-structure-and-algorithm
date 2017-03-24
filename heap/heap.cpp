#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Heap
{
	vector<T> list;

	void bubbleUp();
	void bubbleDown();
	void swap(int child, int parent);
	int getLeftChild(int parent);
	int getRightChild(int parent);
	int getParent(int child);

public:
	Heap();
	void insert(T);
	T remove();
	int getSize();
};

template<class T>
Heap<T>::Heap()
{
}


template<class T>
int Heap<T>::getSize()
{
	return (list.size());
}


template<class T>
void Heap<T>::swap(int child, int parent)
{
	T temp;

	temp = list[child];
	list[child] = list[parent];
	list[parent] = temp;
}


template<class T>
int Heap<T>::getParent(int child)
{
	if (child % 2 == 0) {
		return ((child/2) - 1);
	} else{
		return (child/2);
	}
}


template<class T>
int Heap<T>::getLeftChild(int parent)
{
	return (2 * parent + 1);
}


template<class T>
int Heap<T>::getRightChild(int parent)
{
	return (2 * parent + 2);
}


template<class T>
void Heap<T>::insert(T value)
{
	list.push_back(value);
	bubbleUp();
}


template<class T>
void Heap<T>::bubbleUp()
{
	int child = list.size() - 1;
	int parent = getParent(child);

	while (list[child] > list[parent] && child >= 0 && parent >= 0)
	{
		swap(child, parent);
		child = parent;
		parent = getParent(child);
	}
}


template<class T>
void Heap<T>::bubbleDown()
{
	int parent = 0;

	while (true)
	{
		int left = getLeftChild(parent);
		int right = getRightChild(parent);
		int length = list.size();
		int largest = parent;

		if ((left < length) && (list[left] > list[largest])) {
			largest = left;
		}

		if ((right < length) && (list[right] > list[largest])) {
			largest = right;
		}

		if (largest != parent) {
			swap(largest, parent);
			parent = largest;
		}else {
			break;
		}
	}
}


template<class T>
T Heap<T>::remove()
{
	int child = list.size() - 1;

	swap(child, 0);

	T value = list.back();
	list.pop_back();

	bubbleDown();

	return (value);
}


int main()
{
	int a[] = { 4, 5, 2, 3, 6, 7 };

	Heap<int> heap;
	int len = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < len; i++)
	{
		heap.insert(a[i]);
	}

	while (heap.getSize() > 0)
	{
		cout << "Heap Max\t" << heap.remove() << endl;
	}

	return (0);
}
