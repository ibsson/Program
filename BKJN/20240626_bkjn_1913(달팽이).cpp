#include <stdio.h>
#include <stdlib.h>

void Get_Result(int** snail, int N, int M, int* x, int* y) {

	int tmp = N * N;
	int direction = 1, i = 0;

	while (tmp != 0) {
		if (direction == 1) {
			for (int j = i; j < N; j++) {
				snail[j][i] = tmp;

				if (M == tmp) {
					(*x) = j + 1;
					(*y) = i + 1;
				}

				tmp--;
			}
			direction = 2;
		}
		else if (direction == 2) {
			for (int j = (i + 1); j < N; j++) {
				snail[N - 1][j] = tmp;

				if (M == tmp) {
					(*x) = N;
					(*y) = j + 1;
				}

				tmp--;
			}
			direction = 3;
		}
		else if (direction == 3) {
			for (int j = (N - 2); j >= i; j--) {
				snail[j][N - 1] = tmp;

				if (M == tmp) {
					(*x) = j + 1;
					(*y) = N;
				}

				tmp--;
			}
			direction = 4;
		}
		else if (direction == 4) {
			for (int j = (N - 2); j > i; j--) {
				snail[i][j] = tmp;

				if (M == tmp) {
					(*x) = i + 1;
					(*y) = j + 1;
				}

				tmp--;
			}
			direction = 1;
			N--;
			i++;
		}
	}
}

int main(void) {

	int N = 0, M = 0;

	scanf("%d", &N);
	scanf("%d", &M);

	int** snail = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		snail[i] = (int*)malloc(sizeof(int) * N);
	}

	int x = 0, y = 0;

	Get_Result(snail, N, M, &x, &y);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", snail[i][j]);
		}
		printf("\n");
	}

	printf("%d %d\n", x, y);

	for (int i = 0; i < N; i++) {
		free(snail[i]);
	}
	free(snail);

	return 0;
}

/*
이 문제는 백준 자리배정 문제랑 비슷한 문제여서 쉽게 풀었다. 문제 접근 방법은

1. 방향을 1, 2, 3, 4로 설정해서 N * N 부터 반시계 방향으로 차례대로 넣는다.

로 접근했고 잘 풀렸다. 간단한 구현문제라 쉽게 풀렸다. 문제를 푸는 시간만 조금 단축하면 좋을 것 같다.
*/
