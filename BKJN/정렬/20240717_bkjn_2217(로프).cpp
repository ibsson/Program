#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int Compare(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 < *elem2) return 1;
	else if (*elem1 > *elem2) return -1;
	else return 0;
}

int Get_Max_Weight(int rope[], int N) {

	int max = -1;

	for (int i = 1; i <= N; i++) {
		if (max < (rope[i - 1] * i)) {
			max = rope[i - 1] * i;
		}
	}

	return max;
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	int* rope = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &rope[i]);
	}

	qsort(rope, N, sizeof(int), Compare);

	printf("%d\n", Get_Max_Weight(rope, N));

	return 0;

}

/*
비교적 쉽게 풀렸다.
접근 방식은

1. 배열을 내림차순으로 정렬 한다.
2. 가장 큰 숫자부터 로프의 갯수를 하나씩 늘려가며 줄이 버틸 수 있는 최소 중량과 줄 개수를 곱한 수를 max랑 비교한다.

이렇게 접근 했는데 이대로 풀린 것 같다.

그리디 알고리즘의 특성을 쉽게 이해할 수 있는 좋은 문제였다고 생각한다.
*/
