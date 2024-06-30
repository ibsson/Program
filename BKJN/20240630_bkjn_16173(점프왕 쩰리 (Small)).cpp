#include <stdio.h>
#include <stdlib.h>

int a = 0;

typedef struct Node {
	int Data;
	int check;
}Node;

void Find_Possible_Way(Node** game, int N, int x, int y) {

	if (x > (N - 1)) {
		return;
	}
	else if (y > (N - 1)) {
		return;
	}

	if (game[x][y].check > 0) return;

	game[x][y].check++;

	if (game[x][y].Data == -1) {
		a = 1;
		return;
	}

	Find_Possible_Way(game, N, (x + game[x][y].Data), y);
	Find_Possible_Way(game, N, x, (y + game[x][y].Data));
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	Node** game = (Node**)malloc(sizeof(Node*) * N);
	for (int i = 0; i < N; i++) {
		game[i] = (Node*)malloc(sizeof(Node) * N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &game[i][j].Data);
		}
	}

	Find_Possible_Way(game, N, 0, 0);

	if (a == 1) printf("HaruHaru\n");
	else if (a == 0) printf("Hing\n");

	for (int i = 0; i < N; i++) {
		free(game[i]);
	}
	free(game);

	return 0;
}

/*
처음으로 스스로 풀어본 깊이우선탐색 (DFS)문제다. 접근방식은 이러했다.

1. 오른쪽으로 가다가 N을 넘어가면 아래로 이동.

이걸 재귀함수로 구현하려니까 꽤 헷갈렸다. 그래도 어찌저찌 구현해서 제출을 했는데 메모리초과 라고 나왔다.
그래서 검사했던 노드는 검사하지 않는 방법으로 만들어서 제출했더니 정답이 되었다.

처음으로 스스로 DFS문제를 풀어내었다. 몇달 전까지만 해도 손도 못댔던 문제를 풀어내었다.
DFS에 대한 이해가 조금은 생긴 것 같고, 재귀에 대한 이해도 조금 생긴 것 같다.
하지만 시간이 오래 걸렸다는 점과, 코드를 깔끔하게 만들지 못했다는 점에서 한계를 느꼈고, 더 노력해서 더 깔끔한 코드를 빠르게 만들수 있도록 해야겠다.
그리고 깊이우선탐색 문제는 대부분 너비우선탐색으로도 풀린다고 알고있다. 그러므로 너비우선탐색으로도 한번 더 풀어봐야겠다.
*/
