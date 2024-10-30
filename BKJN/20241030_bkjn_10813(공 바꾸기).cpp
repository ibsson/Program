#include <iostream>
using namespace std;

int main(void) {

	int N = 0, M = 0;

	cin >> N >> M;

	int* basket = new int[N + 1];

	for (int l = 1; l <= N; l++) {
		basket[l] = l;
	}

	int i = 0, j = 0, tmp = 0;

	for (int l = 0; l < M; l++) {
		cin >> i >> j;

		tmp = basket[i];
		basket[i] = basket[j];
		basket[j] = tmp;
	}

	for (int l = 1; l <= N; l++) {
		cout << basket[l] << " ";
	}

	return 0;
}

/*
c++로 기초적인 문제를 풀어보면서 c++사용에 익숙해지고 있고, 백준문제를 단계별로 12번까지 모두 풀어보고 있다.
*/
