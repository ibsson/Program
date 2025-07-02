#include <stdio.h>
#include <string.h>

int ground[51][51] = { 0 };
int check[51][51] = { 0 };
int direction_x[4] = { 1, -1, 0, 0 };
int direction_y[4] = { 0, 0, -1, 1 };

void DFS(int y, int x, int M, int N) {

	check[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = x + direction_x[i];
		int next_y = y + direction_y[i];

		if (next_x >= 0 && next_x < M && next_y >= 0 && next_y < N) {
			if (ground[next_y][next_x] == 1 && check[next_y][next_x] == 0) {
				DFS(next_y, next_x, M, N);
			}
		}
		
		next_x -= direction_x[i];
		next_y -= direction_y[i];
	}
}

int main(void) {

	int T = 0, M = 0, N = 0, K = 0, tmp_1 = 0, tmp_2 = 0, cnt = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		scanf("%d %d %d", &M, &N, &K);

		for (int j = 0; j < K; j++) {
			scanf("%d %d", &tmp_1, &tmp_2);
			ground[tmp_2][tmp_1] = 1;
		}

		for (int j = 0; j < N; j++) {
			for (int l = 0; l < M; l++) {
				if (ground[j][l] == 1 && check[j][l] == 0) {
					DFS(j, l, M, N);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);

		memset(ground, 0, sizeof(ground));
		memset(check, 0, sizeof(check));

		cnt = 0;
	}

	return 0;
}

/*
이 문제는 DFS로 풀었다.
접근 방식은

1. 입력된 인덱스의 배열에 1을 넣는다.
2. 1이 나오고 한번도 방문하지 않은 요소라면 DFS로 인접한 모든 요소를 검사한다.

이렇게 하려고 했다. 생각한 대로 잘 만들어 진 것 같다.
하지만 아직 DFS, BFS 숙련도가 부족한 것 같다.
더 빠르고 더 좋은 코드를 만들 수 있도록 더 노력 해야겠다.
*/
