#include <iostream>
using namespace std;

int a[5] = { 9, 4, 3, 8, 1 };

void makeHeap(int root, int lastNode) {
	int parent = root, rootval = a[root], leftson = (2 * parent) + 1;

	while (leftson <= lastNode) {
		int rightson = leftson + 1;
		int son = leftson;

		if (rightson <= lastNode && a[leftson] < a[rightson]) {
			son = rightson;
		}

		if (rootval < a[son]) {
			a[parent] = a[son];
			parent = son;
			leftson = 2 * parent + 1;
		}
		else {
			break;
		}
	}

	a[parent] = rootval;
}

void heapSort(int n) {
	for (int i = (n / 2) - 1; i >= 0; i--) {
		makeHeap(i, n - i);
	}

	for (int i = (n - 1); i > 0; i--) {
		int tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;

		makeHeap(0, i - 1);
	}
}

int main() {
	heapSort(5);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
