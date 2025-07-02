#include <stdio.h>
#include <stdlib.h>

int ComparePoint(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 < *elem2) return 1;
	else if (*elem1 > *elem2) return -1;
	else return 0;
}

int main(void) {

	int A[10] = { 0 };
	int T = 0, N = 3;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &A[j]);
		}

		qsort((void*)A, 10, sizeof(int), ComparePoint);

		printf("%d\n", A[2]);
	}

	return 0;
}

/*
qsort에 대해서 계속 써보면서 성능을 파악해가고 있고, 활용법을 계속 익혀나가고 있다.
*/
