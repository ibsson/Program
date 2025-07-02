#include <stdio.h>
#include <stdlib.h>

int Compare(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 < *elem2) return 1;
	else if (*elem1 > *elem2) return -1;
	else return 0;
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), Compare);

	int check = -1;

	for (int i = 0; i < (N - 2) ; i++) {
		if (arr[i] < arr[i + 1] + arr[i + 2]) {
			printf("%d\n", arr[i] + arr[i + 1] + arr[i + 2]);
			check = 0;
			break;
		}
	}

	if (check == -1) printf("%d\n", check);

	return 0;
}

/*
이 문제는 내림차순으로 정렬 후 삼각형 성립 조건을 이용하여 쉽게 풀었다.
*/
