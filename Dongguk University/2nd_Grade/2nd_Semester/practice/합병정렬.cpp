#include <iostream>
using namespace std;

int a[5] = { 9, 4, 3, 8, 1 };
int b[5];

void merge(int left, int right, int mid) {
	int leftptr = left, rightptr = mid + 1, bufptr = left;

	while (leftptr <= mid && rightptr <= right) {
		if (a[leftptr] < a[rightptr]) {
			b[bufptr++] = a[leftptr++];
		}
		else {
			b[bufptr++] = a[rightptr++];
		}
	}

	while (leftptr <= mid) {
		b[bufptr++] = a[leftptr++];
	}
	while (rightptr <= right) {
		b[bufptr++] = a[rightptr++];
	}

	for (int i = left; i <= right; i++) {
		a[i] = b[i];
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, right, mid);
	}
}

int main() {
	mergeSort(0, 4);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
