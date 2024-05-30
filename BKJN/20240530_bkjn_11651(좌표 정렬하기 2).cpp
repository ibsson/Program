#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int X;
	int Y;
}point;

int Compare(const void* elem1, const void* elem2) {

	point* a = (point*)elem1;
	point* b = (point*)elem2;

	if (a->Y > b->Y) return 1;
	else if (a->Y < b->Y) return -1;
	else {
		if (a->X < b->X) return -1;
		else return 1;
	}

	return 0;
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	point* A = (point*)malloc(sizeof(point) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i].X, &A[i].Y);
	}

	qsort(A, N, sizeof(point), Compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", A[i].X, A[i].Y);
	}

	free(A);

	return 0;
}

/*
이 문제는 그냥 11650번 문제에서 Y로 먼저 정렬하면 되는 문제였다.
그래서 되게 쉽게 풀 수 있었다.
*/
