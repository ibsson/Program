#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N = 0;

	scanf("%d", &N);

	int* score = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}

	int cnt = 0;

	for (int i = (N - 2); i >= 0; i--) {
		while (score[i] >= score[i + 1]) {
			score[i]--;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	free(score);

	return 0;
}

/*
굉장히 쉽게 풀었다.
접근 방식은

1. 바로 뒤 index의 요소보다 1이 더 작을 때까지 뺀다.

이렇게 접근해서 그대로 구현했는데 깔끔하게 잘 됐다.
계속 이런 문제를 풀고, 문제를 풀기 전에 방향을 잡고 풀다보니
문제를 푸는 속도도 빨라지고, 오류가 나오는 부분도 찾기가 쉽다.
그리고 문제를 보고 방향성을 잡는것이 쉬워져서 문제를 보는 눈이 좋아진 것 같다고 느꼈다.
더 노력해서 더 좋은 코드를 만들 수 있도록 해야겠다!
*/
