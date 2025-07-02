#include <stdio.h>
#include <stdlib.h>

int Get_Result(char** floor, int N, int M) {

	int cnt_1 = 0, cnt_2 = 0, result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (floor[i][j] == '-') {
				result += cnt_2;
				cnt_2 = 0;

				if (j == 0) {
					cnt_1++;
					continue;
				}

				if (floor[i][j - 1] != '-') {
					cnt_1++;
				}
			}
			else if (floor[i][j] == '|') {
				result += cnt_1;
				cnt_1 = 0;

				if (i == 0) {
					cnt_2++;
					continue;
				}

				if (floor[i - 1][j] != '|') {
					cnt_2++;
				}
			}
		}
		result += cnt_1 + cnt_2;
		cnt_1 = 0, cnt_2 = 0;
	}

	return result;
}

int main(void) {

	int N = 0, M = 0;

	scanf("%d %d", &N, &M);

	char** floor = (char**)malloc(sizeof(char*) * N);

	for (int i = 0; i < N; i++) {
		floor[i] = (char*)malloc(sizeof(char) * (M + 1));
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", floor[i], (M + 1));
	}

	printf("%d\n", Get_Result(floor, N, M));

	for (int i = 0; i < N; i++) {
		free(floor[i]);
	}
	free(floor);

	return 0;
}

/*
이 코드도 무난하게 풀었다. 접근 방식은

1. - 면 왼쪽 검사
2. |면 위쪽 검사

이런 방식으로 풀었는데 한번에 잘 구현되었다.
동적 할당 하고 free해주는걸 자꾸 까먹는데 앞으로는 까먹지 말도록 노력해야겠다.
*/
