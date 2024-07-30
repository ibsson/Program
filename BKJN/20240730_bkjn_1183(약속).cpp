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

	int* A = (int*)malloc(sizeof(int) * N);
	int* B = (int*)malloc(sizeof(int) * N);
	int* sum = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i], &B[i]);
		sum[i] = -(A[i] - B[i]);
	}

	if (N % 2 != 0) {
		printf("1\n");
		return 0;
	}
	else {
		qsort(sum, N, sizeof(int), Compare);

		printf("%d\n", sum[N / 2] - sum[(N / 2) - 1] + 1);
	}

  free(A);
  free(B);
  free(sum);

	return 0;
}

/*
이 문제는 풀다가 모르겠어서 검색해서 참고했다.
그래프를 그려보면 나오는 규칙성이었다.
N이 홀수일때는 무조건 1, N이 짝수일때는 sum[N/2] - sum[(N/2)-1] + 1 개의 규칙성이 있었다.
사실 문제를 풀면서 그래프를 그려보면 규칙성이 나올 것 같다는 생각을 했지만 경우의 수가 너무 많을 것 같아서 포기를 했다.
너무 어리석었다. 조금만 그래프를 그려봐도 나오는 규칙성인데..
반성하는 계기가 되었다. 문제가 풀리는데 도움이 되는 방법이라고 생각했으면 시도라도 해보는게 맞는 것이다.
앞으로는 문제를 푸는데 도움이 되는 방법이라는 생각이 들면 무조건 시도를 해봐야겠다고 다짐을 했다.
나에 대한 반성을 하게 해주고 내가 아직 부족하다는 것을 깨닫게 해주는 문제였다.
*/
