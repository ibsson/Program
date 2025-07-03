#include <iostream>
using namespace std;

int main(void) {

	int N = 0, M = 0;

	cin >> N >> M;

	int* basket = new int[N + 1];

	int i = 0, j = 0;
	int tmp = 0;

	for (int l = 1; l <= N; l++) {
		basket[l] = l;
	}

	for (int l = 0; l < M; l++) {
		cin >> i >> j;

		for (int m = 0; m <= (j - i) / 2; m++) {
			tmp = basket[i + m];
			basket[i + m] = basket[j - m];
			basket[j - m] = tmp;
		}
	}

	for (int l = 1; l <= N; l++) {
		cout << basket[l] << " ";
	}

	delete[] basket;

	return 0;
}
