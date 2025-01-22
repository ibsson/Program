#include <stdio.h>

long long int fibo(int n) {
	long long int num[91] = { 0 };
	num[0] = 0;
	num[1] = 1;
	for (int i = 2; i <= n; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}
	return num[n];
}

int main(void) {

	int n = 0;

	scanf("%d", &n);

	printf("%lld\n", fibo(n));

	return 0;
}
