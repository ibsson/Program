#include <stdio.h>
#include <string.h>

int result[10] = { 0 };
int visited[10] = { 0 };

void Get_Sequence(int index, int N, int M, int cnt, int arr_index) {

	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");

		visited[index] = 0;

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] != 1) {
			visited[i] = 1;
			result[arr_index] = i;

			Get_Sequence(i, N, M, (cnt + 1), (arr_index + 1));

			visited[i] = 0;
		}
	}
}

int main(void) {

	int N = 0, M = 0;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		result[1] = i;
		visited[i] = 1;

		Get_Sequence(i, N, M, 1, 2);

		memset(result, 0, sizeof(result));
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}

/*
이 문제는 백트래킹으로 풀었다.
구현하는데 index가 헷갈려서 조금 헤매었지만 손으로 쓰면서 푸니까 잘 풀렸다.
*/
