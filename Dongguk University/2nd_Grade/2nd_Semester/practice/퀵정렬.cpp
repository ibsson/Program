#include <iostream>
using namespace std;

int a[5] = { 9, 4, 3, 8, 1 };

int partition(int left, int right) {
	int pivot = a[right];
	int i = (left - 1);

	for (int j = left; j < right; j++) {
		if (a[j] <= pivot) {
			i++;
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	int tmp = a[i + 1];
	a[i + 1] = a[right];
	a[right] = tmp;

	return (i + 1);
}

void quickSort(int left, int right) {
	int k;
	if (left < right) {
		k = partition(left, right);
		quickSort(left, k - 1);
		quickSort(k + 1, right);
	}
}

int main() {
	quickSort(0, 4);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
