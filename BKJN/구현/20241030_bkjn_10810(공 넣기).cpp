#include <iostream>
using namespace std;

int main(void) {

	int N = 0, M = 0;
	int i = 0, j = 0, k = 0;

	cin >> N >> M;

	int* basket = new int[N + 1];

	for (int l = 0; l < M; l++) {
		cin >> i >> j >> k;

		for (int m = i; m <= j; m++) {
			basket[m] = k;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << basket[i] << " ";
	}

	delete[] basket;

	return 0;
}

/*
c++로 동적할당을 이용해서 처음 문제를 풀어봤다.
어떻게 사용하는지 잘 이해가 된 것 같다.
*/
