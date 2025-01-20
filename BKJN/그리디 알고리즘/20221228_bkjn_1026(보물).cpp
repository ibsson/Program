#include <stdio.h>

#define SWAP(a, b) ( (a) ^= (b) ^= (a) ^= (b))

int main() {

	int A[50] = { 0 };
	int B[50] = { 0 };
	int N = 0;
	int S = 0;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &A[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &B[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int k = i; k < N; k++) {
			if (A[i] > A[k]) {
				SWAP(A[i], A[k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = i; k < N; k++) {
			if (B[i] < B[k]) {
				SWAP(B[i], B[k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		S += (A[i] * B[i]);
	}

	printf("%d\n", S);

	return 0;
}
