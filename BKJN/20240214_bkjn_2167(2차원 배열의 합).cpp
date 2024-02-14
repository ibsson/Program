#include <stdio.h>

int num[300][300] = { 0 };

int main(void) {

	int N = 0;
	int M = 0;
	int K = 0;
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int result = 0;
	
	scanf("%d %d", &N, &M);

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			scanf("%d", &num[a][b]);
		}
	}

	scanf("%d", &K);

	for (int a = 0; a < K; a++) {
		scanf("%d %d %d %d", &i, &j, &x, &y);

		for (int b = i - 1; b <= x - 1; b++) {
			for (int c = j - 1; c <= y - 1; c++) {
				result += num[b][c];
			}
		}

		printf("%d\n", result);

		result = 0;
	}

	return 0;
}
