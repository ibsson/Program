#include <stdio.h>
#include <stdlib.h>

int Get_Max(int num[], int N) {

	int max = -1001;

	for (int i = 0; i < N; i++) {
		int tmp = 0;

		for (int j = i; j < N; j++) {
			tmp += num[j];

			if (max < tmp) max = tmp;
		}
	}

	return max;
}

int main(void) {

	int T = 0, N = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		int* num = (int*)malloc(sizeof(int) * N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &num[j]);
		}

		printf("%d\n", Get_Max(num, N));

		free(num);
	}

	return 0;
}

/*
이 문제도 브루트포스와 다이나믹프로그래밍을 활용해서 쉽게 풀었다.
*/
