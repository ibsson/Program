#include <stdio.h>
#include <stdlib.h>

int Compare(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2) return 1;
	else if (*elem1 < *elem2) return -1;
	else return 0;
}

int main(void) {

	int N = 0, L = 0, cnt = 0;

	scanf("%d %d", &N, &L);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), Compare);

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if ((arr[j] - arr[i]) > (L - 1)) {
				cnt++;
				i = j - 1;
				break;
			}

			if (j == (N - 1)) {
				cnt++;
				i = j;
			}
		}
	}

	printf("%d\n", cnt);

	free(arr);

	return 0;
}

/*
이 문제의 접근 방식은

1. 고정된 인덱스와의 길이의 차가 (L - 1) 보다 클때 cnt를 1씩 더한다.
2. 바로 다음 인덱스를 고정 후 1을 반복한다.

이렇게 풀었다.
의도한대로 그대로 구현한 코드인 것 같다.
*/
