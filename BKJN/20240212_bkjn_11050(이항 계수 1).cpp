#include <stdio.h>

int cnt(int n, int k) {

	int a = 1;
	int b = 1;
	int c = 1;
	int tmp = 0;

	for (int i = 1; i <= n; i++) {
		a *= i;
	}

	for (int i = 1; i <= k; i++) {
		b *= i;
	}

	for (int i = 1; i <= (n - k); i++) {
		c *= i;
	}

	tmp = a / (b * c);

	return tmp;
}

int main(void) {

	int N = 0;
	int K = 0;

	scanf("%d %d", &N, &K);

	printf("%d\n", cnt(N, K));

	return 0;
}
