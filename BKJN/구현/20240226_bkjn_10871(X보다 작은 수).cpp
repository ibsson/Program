#include <stdio.h>

int A[10000] = { 0 };

int main(void) {

	int N = 0, X = 0, check = 0;

	scanf("%d %d", &N, &X);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {

		if (A[i] < X) {
			if (check == 0) {
				printf("%d", A[i]);
				check++;
			}
			else {
				printf(" %d", A[i]);
			}
		}
		
		if (i == N - 1) printf("\n");
	}

	return 0;
}
