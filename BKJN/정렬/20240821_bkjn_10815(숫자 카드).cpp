#include <stdio.h>
#include <stdlib.h>

int card[10000001] = { 0 };
int find[10000001] = { 0 };
int result[10000001] = { 0 };

int Compare(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2) return 1;
	else if (*elem1 < *elem2) return -1;
	else return 0;
}

void Binary_Search(int N, int index) {

	int left = 0, right = 0, mid = 0;

	right = (N - 1);

	while (left <= right) {
		mid = (left + right) / 2;

		if (find[index] == card[mid]) {
			result[index]++;
			return;
		}
		else if (find[index] > card[mid]) left = mid + 1;
		else right = mid - 1;
	}
}

int main(void) {

	int N = 0, M = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}

	qsort(card, N, sizeof(int), Compare);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &find[i]);
	}

	for (int i = 0; i < M; i++) {
		Binary_Search(N, i);
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}

/*
이 문제는 선형탐색으로 풀기에는 범위가 너무 커서 이진탐색을 이용해서 쉽게 풀었다.
*/
