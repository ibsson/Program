#include <iostream>
using namespace std;

int a[5] = { 9, 2, 3, 8, 1 };

void bubbleSort(int n) {
	bool chk = false;

	while (!chk) {
		chk = true;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				chk = false;
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
}

int main() {
	bubbleSort(5);

	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}
