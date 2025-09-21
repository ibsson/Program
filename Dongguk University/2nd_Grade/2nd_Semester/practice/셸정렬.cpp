#include <iostream>
using namespace std;

int a[5] = { 9, 2, 3, 8, 1 };

void shellSort(int n) {
	int h = 1;
	while(h < n){
		h = (h * 3) + 1;
	}

	while (h > 0) {
		h /= 3;

		for (int i = h; i < n; i++) {
			int val = a[i];
			int j = i;

			while (j >= h && a[j - h] > val) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = val;
		}
	}
}

int main() {
	shellSort(5);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
