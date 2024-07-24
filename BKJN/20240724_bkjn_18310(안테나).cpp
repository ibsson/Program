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

	int* location = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &location[i]);
	}

	qsort(location, N, sizeof(int), Compare);

	if (N % 2 == 0) {
		printf("%d\n", location[(N / 2) - 1]);
	}
	else {
		printf("%d\n", location[N / 2]);
	}

	return 0;
}

/*
이 문제는 처음에는 모든 인덱스의 배열요소를 검사해서 거리차이가 가장 작은 값을 출력하려고 했는데
시간초과가 떠서 코드를 바꿨다.
계속 손으로 테스트를 해본 결과 공통점이 발견이 되었다.
결과는 항상 정렬된 배열에서 중간값이 나온다는 것이었다.
N이 짝수일때는 N/2 - 1번째, N이 홀수일때는 N/2번째 인덱스에서 나왔다.
그래서 한번 만들어 봤더니 정답이었다.

이 문제는 결과값만 나오면 되는 '그리디'문제의 좋은 예라고 생각한다.
그리고 계속 손으로 문제를 테스트 해보면서 문제를 풀어나가는것이 정말 중요하다는 것을 느꼈다.
원래도 손으로 쓰면서 계속 테스트를 했지만,
앞으로는 손을 더 적극적으로 많이 써서 테스트를 하며 코드를 짜는것을 더욱 습관화 해야겠다고 생각했다.
*/
