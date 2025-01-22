#include <stdio.h>

int dp[501][501] = { 0 };

void Get_Max(int n) {

	for (int i = (n - 2); i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (dp[i + 1][j] > dp[i + 1][j + 1]) {
				dp[i][j] += dp[i + 1][j];
			}
			else {
				dp[i][j] += dp[i + 1][j + 1];
			}
		}
	}
}

int main(void) {

	int n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &dp[i][j]);
		}
	}

	Get_Max(n);

	printf("%d\n", dp[0][0]);

	return 0;
}

/*
이 문제는 처음에 DFS로 풀었다가 시간초과가 나서 DP로 풀어보았는데,
아무리 생각해도 평소에 풀던 DP로는 풀리지 않았다.
그래서 검색을 해서 참고를 했는데, 항상 위에서부터 아래로 문제를 풀어서 아래에서 위로 가는 방법을 미처 생각하지 못했다.
아래부터 시작해서 규칙을 찾아보니 쉽게 규칙을 찾을 수 있었다.
if (dp[i + 1][j] > dp[i + 1][j + 1]) {
	dp[i][j] += dp[i + 1][j];
}
else {
	dp[i][j] += dp[i + 1][j + 1];
}
의 규칙이었다.
이 문제를 통해 앞으로는 한가지 시각에만 얽매어서 풀지 말아야겠다는 생각을 했다.
*/
