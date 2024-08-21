#include <stdio.h>
#include <stdlib.h>

long long int A[100001] = { 0 };
long long int B[100001] = { 0 };
int result[100001] = { 0 };

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

		if (A[mid] == B[index]) {
			result[index] = 1;
			return;
		}
		else if (A[mid] > B[index]) right = mid - 1;
		else left = mid + 1;
	}
}

int main(void) {

	int N = 0, M = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	qsort(A, N, sizeof(long long int), Compare);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%lld", &B[i]);
	}

	for (int i = 0; i < M; i++) {
		Binary_Search(N, i);
	}

	for (int i = 0; i < M; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}

/*
이 문제는 배열의 범위가 굉장히 크기 때문에 선형탐색을 쓰지 않고 이진탐색을 사용해서 쉽게 풀었다.
*/
