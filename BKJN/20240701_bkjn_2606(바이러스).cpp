#include <stdio.h>
#include <stdlib.h>

void Make_Matrix(int** Computer, int y, int x) {

	Computer[y - 1][x - 1] = 1;
	Computer[x - 1][y - 1] = 1;
}

void dfs(int** Computer, int y, int T, int* Visited) {

	Visited[y] = 1;

	for (int i = 0; i < T; i++) {
		if (Computer[y][i] == 1 && Visited[i] != 1) {
			dfs(Computer, i, T, Visited);
		}
	}
}

int main(void) {

	int T = 0, N = 0;

	scanf("%d", &T);

	int** Computer = (int**)malloc(sizeof(int**) * T);
	for (int i = 0; i < T; i++) {
		Computer[i] = (int*)malloc(sizeof(int*) * T);
	}

	int* Visited = (int*)malloc(sizeof(int*) * T);

	scanf("%d", &N);

	int num1 = 0, num2 = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &num1, &num2);

		Make_Matrix(Computer, num1, num2);
	}

	dfs(Computer, 0, T, Visited);

	int cnt = 0;

	for (int i = 1; i < T; i++) {
		if (Visited[i] == 1) cnt++;
	}

	printf("%d\n", cnt);

	for (int i = 0; i < T; i++) {
		free(Computer[i]);
	}
	free(Computer);

	return 0;
}

/*
이 코드는 인접행렬과 dfs를 이용해서 풀려고 했다.
접근 방식은

1. 인접행렬을 만든다.
2. dfs로 모든 노드를 검사를 하고 이미 간 노드는 표시를 해놓는다.

이렇게 풀려고 했는데 그래도 잘 구현 된 것 같다.
시간이 굉장히 오래 걸렸는데, 계속해서 dfs 문제를 풀어보다 보면 빨라질것이라고 생각한다.
인접행렬을 이용하는게 처음이라 익숙치가 않았는데 인접행렬을 어떤식으로 이용해야 하는지 조금은 이해가 되었다.
인접행렬과 dfs를 한꺼번에 활용해서 푸는게 쉽지만은 않았다. 
하지만 이런 문제를 어떤식으로 접근하는지 조금은 알게 되었으니 앞으로 이런 문제를 보았을때 방향성을 쉽게 잡을 수 있을 것 같다.
이 문제를 인접리스트로도 풀어봐야겠다.
*/
