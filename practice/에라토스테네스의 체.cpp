//소수 구하는 알고리즘

#include <stdio.h>

int num[1000001] = { 0 };

void eratos(int M, int N) {

	num[1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int k = 2; k * i <= N; k++) {
			num[k * i] = 1;
		}
	}
}

int main(void) {

	int M = 0;
	int N = 0;

	scanf_s("%d", &M);
	scanf_s("%d", &N);

	eratos(M, N);

	for (int j = M; j <= N; j++) {
		if (num[j] == 0) printf("%d\n", j);
	}

	return 0;
}
