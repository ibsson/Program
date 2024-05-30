#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int X;
	int Y;
}point;

int Compare(const void* elem1, const void* elem2) {

	point* a = (point*)elem1;
	point* b = (point*)elem2;

	if (a->X > b->X) return 1;
	else if (a->X < b->X) return -1;
	else {
		if (a->Y < b->Y) return -1;
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
이 코드는 전에 틀렸던 문제이다. 이번에 정렬을 공부하면서 다시 풀어보았다.
전에 만든 qsort에서 비교함수를 수정하여 코드를 짰다.
비교함수를 어떻게 수정해야 할 지 알게 되었고 작동 방식에 대해서도 어느정도 이해 한 것 같다.
그리고 구조체를 qsort에 보낼때 3번째 인자에 sizeof(int)를 보내서 계속 이상하게 값이 나왔는데 앞으로 이런 실수 하지 않도록 해야겠다.
*/
