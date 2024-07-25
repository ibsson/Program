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

	int N = 0;

	scanf("%d", &N);

	int* rank = (int*)malloc(sizeof(int) * N);

	long long int sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &rank[i]);
	}

	qsort(rank, N, sizeof(int), Compare);

	for (int i = 0; i < N; i++) {
		sum += abs(rank[i] - (i + 1));
	}

	printf("%lld\n", sum);

	return 0;
}

/*
이 문제는 처음에 정렬 후 각자 맞는 순위에 넣으면서 최솟값을 찾으려고 했으나 시간초과가 났다.
그래서 다른 방법을 생각해봤더니 그냥 정렬 후, 1등부터 끝까지 차례대로 넣는것도 최솟값이 되는 것을 알게되었다.
쉬운 방법으로 그리디 문제를 잘 해결한 것 같다.
*/
