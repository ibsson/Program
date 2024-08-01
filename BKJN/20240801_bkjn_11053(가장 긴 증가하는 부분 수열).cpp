#include <stdio.h>

int main(void) {

	int N = 0;
	int num[1001] = { 0 };
	int dp[1001] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i <= N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int max = -1;

	for (int i = 0; i <= N; i++) {
		if (dp[i] > max) max = dp[i];
	}

	printf("%d\n", max);

	return 0;
}

/*
이 문제는 dp 문제였다.
아직 이런 문제에 익숙치가 않아서 오래동안 생각하다가 결국 검색해서 풀어냈다.
정답 코드를 보면서 이해하는건 쉽지만 내가 정답코드를 만들어 내는건 아직 좀 어려운 것 같다.
dp문제를 더 많이 풀어봐야겠다. 조건 하나하나가 이해하는게 복잡해서 공부를 많이 해야 할 것 같다.
*/
