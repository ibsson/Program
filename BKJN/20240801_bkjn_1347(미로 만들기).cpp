#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pos {
	int x;
	int y;
}Pos;

char maze[51][51] = { 0 };

void Get_Min(Pos* A, int* x_min, int* y_min, int K) {

	for (int i = 0; i <= K; i++) {
		if ((*x_min) > A[i].x) (*x_min) = A[i].x;

		if ((*y_min) > A[i].y) (*y_min) = A[i].y;
	}
}

void Get_Max(Pos* A, int* x_max, int* y_max, int K) {

	for (int i = 0; i <= K; i++) {
		if ((*x_max) < A[i].x) (*x_max) = A[i].x;

		if ((*y_max) < A[i].y) (*y_max) = A[i].y;
	}
}

Pos Move_Front(int sight, Pos pre, Pos cur) {

	if (sight == 1) {
		cur.x = pre.x;
		cur.y = pre.y + 1;
	}
	else if (sight == 2) {
		cur.x = pre.x - 1;
		cur.y = pre.y;
	}
	else if (sight == 3) {
		cur.x = pre.x;
		cur.y = pre.y - 1;
	}
	else if (sight == 4) {
		cur.x = pre.x + 1;
		cur.y = pre.y;
	}

	return cur;
}

void Move(char direction[], int sight, int N) {

	int k = 0;
	Pos* tmp = (Pos*)malloc(sizeof(Pos) * N);
	tmp[0].x = 0; tmp[0].y = 0;

	for (int i = 0; i < N; i++) {
		if (direction[i] == 'R') {
			if (sight != 4) sight++;
			else if (sight == 4) sight = 1;
		}
		else if (direction[i] == 'L') {
			if (sight != 1) sight--;
			else if (sight == 1) sight = 4;
		}
		else if (direction[i] == 'F') {
			tmp[k + 1] = Move_Front(sight, tmp[k], tmp[k + 1]);
			k++;
		}
	}

	int x_min = 60, y_min = 60, x_max = -1, y_max = -1;

	Get_Min(tmp, &x_min, &y_min, k);
	Get_Max(tmp, &x_max, &y_max, k);

	for (int i = 0; i <= k; i++) {
		tmp[i].x -= x_min;
		tmp[i].y -= y_min;

		maze[tmp[i].y][tmp[i].x] = '.';
	}

	x_max -= x_min; y_max -= y_min;
	x_min -= x_min; y_min -= y_min;

	for (int i = y_min; i <= y_max; i++) {
		for (int j = x_min; j <= x_max; j++) {
			if (maze[i][j] != '.') maze[i][j] = '#';
		}
	}

	for (int i = y_min; i <= y_max; i++) {
		for (int j = x_min; j <= x_max; j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

int main(void) {

	int N = 0, sight = 1;
	char direction[51] = { 0 };

	scanf("%d", &N);
	scanf("%s", direction, sizeof(direction));

	Move(direction, sight, N);

	return 0;
}

/*
이 문제는 구현하는데 집중했다. 접근 방법은

1. 방향별로 숫자를 정해서 시작점을 (0, 0)으로 한 후 방향대로 가는 쪽으로 위치를 변경한다.
2. x,y 최대 위치와 x,y 최소 위치를 경계로 한 후 그 안에 .이 아닌 곳을 #으로 채운다

그대로 잘 구현되었다. 하지만 시간이 굉장히 오래 걸렸다.
그래도 나에게 꽤 어려운 수준의 코드를 스스로 풀어내서 좋았다.
*/
