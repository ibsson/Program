#include <iostream>
using namespace std;

int a[5] = { 9, 2, 3, 8, 1 };

void insertionSort(int n) {
	for (int i = 1; i < n; i++) {
		int val = a[i];
		int j = i;
		
		while (a[j - 1] > val) {
			a[j] = a[j - 1];
			j--;

			if (j == 0) break;
		}

		a[j] = val;
	}
}

int main() {
	insertionSort(5);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
