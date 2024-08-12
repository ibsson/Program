#include <stdio.h>

int city[10][10] = { 0 };
int visit[11] = { 0 };
int min = 1000000000;

void Go_City(int start, int index, int N, int sum) {

	int cnt = 0;

	visit[index] = 1;

	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			cnt++;
			break;
		}
	}

	if (cnt == 0) {
		
		if (city[index][start] != 0) {
			sum += city[index][start];

			if (min > sum) min = sum;
		}

		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == 0 && city[index][i] != 0) {
			visit[i] = 1;
			Go_City(start, i, N, sum + city[index][i]);
			visit[i] = 0;
		}
	}
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &city[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		Go_City(i, i, N, 0);
		visit[i] = 0;
	}

	printf("%d\n", min);

	return 0;
}

/*
이 문제는 DFS로 풀었다.
문제를 처음에 잘 구현한 줄 알았지만, 조건을 하나 빠트렸었다.
마지막에 돌아갈 수 없을때의 경우도 고려를 해버려서 답이 계속 틀렸었다.
이 조건을 생각을 못해서 시간을 많이 잡아먹었다.
앞으로는 조건을 처음에 잘 파악하고, 그 조건을 잊지않게 적어놓고 문제를 풀기 시작하는 습관을 들여야겠다.
*/
