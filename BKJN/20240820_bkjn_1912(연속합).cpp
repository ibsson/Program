#include <stdio.h>

int num[100002] = { 0 };
int dp[100002] = { 0 };

int main(void) {

	int n = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	dp[1] = num[1];
	int max = dp[1];

	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] > 0) dp[i] = dp[i - 1] + num[i];
		else dp[i] = num[i];

		if (max < dp[i]) max = dp[i];
	}

	printf("%d\n", max);

	return 0;
}


/*
이 문제는 dp로 풀어냈다.
바로 전의 연속합이 음수면 num[i]까지의 연속합의 최대는 자기자신이고, 
아니면 num[i]까지의 연속합의 최대는 자기자신과 바로 전의 연속합을 더하는것이라는 규칙을 찾아내서 쉽게 풀었다.
*/
