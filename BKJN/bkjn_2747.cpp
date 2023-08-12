#include <stdio.h>

int fibo_num[46];

int fibo(int n) {
	
	fibo_num[0] = 0;
	fibo_num[1] = 1;

	for (int i = 2; i <= n; i++) {
		fibo_num[i] = fibo_num[i - 1] + fibo_num[i - 2];
	}
	
	return fibo_num[n];
}

int main(void) {

	int n = 0;

	scanf("%d", &n);

	int result = fibo(n);

	printf("%d\n", result);

	return 0;
}
