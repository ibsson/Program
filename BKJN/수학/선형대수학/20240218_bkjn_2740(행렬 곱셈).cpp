#include <stdio.h>

int A[100][100];
int B[100][100];

void Matrix_multiplication(int n, int m, int k) {

	int tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				tmp += A[i][l] * B[l][j];
			}
			printf("%d", tmp);
			if (j == k - 1) {
				printf("\n");
				tmp = 0;
				break;
			}
			printf(" ");
			tmp = 0;
		}
	}
}

int main(void){

	int N = 0;
	int M = 0;
	int K = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	scanf("%d %d", &M, &K);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	Matrix_multiplication(N, M, K);

	return 0;
}
