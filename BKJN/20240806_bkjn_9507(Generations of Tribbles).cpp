#include <stdio.h>

long long int fibo[70] = { 0 };

void koong(int n) {

	fibo[0] = 1, fibo[1] = 1, fibo[2] = 2; fibo[3] = 4;

	for (int i = 4; i <= n; i++) {
		fibo[i] = fibo[i - 4] + fibo[i - 3] + fibo[i - 2] + fibo[i - 1];
	}
}

int main(void) {

	int t = 0;
	int num[70] = { 0 };

	scanf("%d", &t);

	koong(67);

	for (int i = 0; i < t; i++) {
		scanf("%d", &num[i]);

		printf("%lld\n", fibo[num[i]]);
	}

	return 0;
}

/*
이 문제는 다이나믹 프로그래밍으로 피보나치 문제를 풀듯이 풀어서 쉽게 풀리는 문제였다.
*/
