#include <stdio.h>

int fibo[1000001] = { 0 };

void fib(int n) {

	fibo[0] = 0, fibo[1] = 1, fibo[2] = 1;

	for (int i = 3; i <= n; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000007;
	}
}

int main(void) {

	int n = 0;

	scanf("%d", &n);

	fib(n);

	printf("%d\n", fibo[n]);

	return 0;
}

/*
이 문제도 일반적인 피보나치수열 문제인데, 범위가 굉장히 커서 1000000007으로 나눈 수를 출력하면 되는 문제였다.
dp로 모든 수를 1000000007으로 나눠서 배열에 저장해서 풀면 되는 문제였다.
*/
