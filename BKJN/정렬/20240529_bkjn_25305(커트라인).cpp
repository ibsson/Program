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

	int N = 0, k = 0;
	int score[10001] = { 0 };

	scanf("%d %d", &N, &k);

	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}

	qsort((void*)score, N, sizeof(int), ComparePoint);

	printf("%d\n", score[k - 1]);

	return 0;
}
