#include <stdio.h>

int main(void) {

	int A = 1, B = 0, K = 0;

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int tmp = A;

		if (B != 0) {
			for (int j = 0; j < B; j++) {
				A++;
			}
		}

		if (tmp != 0) {
			for (int j = 0; j < tmp; j++) {
				A--;
				B++;
			}
		}
	}

	printf("%d %d\n", A, B);

	return 0;
}

/*
이 문제는 다이나믹프로그래밍으로 쉽게 풀었다.
*/
