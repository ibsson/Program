#include <iostream>
using namespace std;

int a[5] = { 9, 2, 3, 8, 1 };

void SelectionSort(int n) {
	for (int i = 0; i < n - 1; i++) {
		int minidx = i;
		for (int j = minidx + 1; j < n; j++) {
			if (a[minidx] > a[j]) {
				minidx = j;
			}
		}

		if (minidx != i) {
			int tmp = a[minidx];
			a[minidx] = a[i];
			a[i] = tmp;
		}
	}
}

int main() {
	SelectionSort(5);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
