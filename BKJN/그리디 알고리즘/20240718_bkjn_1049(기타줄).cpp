#include <stdio.h>
#include <stdlib.h>

int Compare(const void* _elem1, const void* _elem2) {

	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2) return 1;
	else if (*elem1 < *elem2) return -1;
	else return 0;
}

int Get_Price(int Package, int Piece, int N, int M) {

	int cnt = 0, price = 0;

	if (((N / 6) + 1) * Package < (Package * (N / 6)) + (Piece * (N % 6))) price = ((N / 6) + 1) * Package;
	else price = (Package * (N / 6)) + (Piece * (N % 6));

	if (N * Piece < price) price = N * Piece;
	
	return price;
}

int main(void) {

	int N = 0, M = 0;

	scanf("%d %d", &N, &M);

	int* Package = (int*)malloc(sizeof(int) * M);
	int* Piece = (int*)malloc(sizeof(int) * M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &Package[i], &Piece[i]);
	}

	qsort(Package, M, sizeof(int), Compare);
	qsort(Piece, M, sizeof(int), Compare);

	printf("%d\n", Get_Price(Package[0], Piece[0], N, M));

	free(Package);
	free(Piece);

	return 0;
}

/*
이 문제의 접근 방식은

1. 패키지와 낱개 둘 다 가장 작은 수를 고른다
2. 모두 패키지로 살때, 패키지와 낱개 나눠서 살때, 모두 낱개로 살때 로 경우를 나누어서 셋 중 가장 작은 값을 찾는다

이렇게 풀었다. 그리디 알고리즘으로 풀었다.
그리디 문제를 계속 풀어보니까 감이 생기는 것 같다.
문제를 일반화를 시키니까 (최저 가격으로만 계산을 한다 등) 문제가 굉장히 쉽게 풀린다.
앞으로도 계속 이렇게 일반화를 시키는 연습을 해야겠다.
*/
