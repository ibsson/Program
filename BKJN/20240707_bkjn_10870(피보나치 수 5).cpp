#include <stdio.h>

int fibo(int n) {

	if (n == 0) return 0;
	else if (n <= 1) return 1;

	return fibo(n - 1) + fibo(n - 2);
}

int main(void) {

	int n = 0;

	scanf("%d", &n);

	printf("%d\n", fibo(n));

	return 0;
}
