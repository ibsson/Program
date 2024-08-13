#include <stdio.h>
#include <string.h>

int dp[42] = { 0 };

void fibo(int N) {

	if (N == 0) {
		dp[0] = 1;
		dp[1] = 0;
		return;
	}
	else if (N == 1) {
		dp[0] = 0;
		dp[1] = 1;
		return;
	}

	dp[N]++;

	for (int i = N; i >= 2; i--) {
		dp[i - 1] += dp[i];
		dp[i - 2] += dp[i];
	}
}

int main(void) {

	int T = 0, N = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);

		fibo(N);

		printf("%d %d\n", dp[0], dp[1]);

		memset(dp, 0, sizeof(dp));
	}


	return 0;
}

/*
이 문제는 dp를 이용해서 풀었다.
내 스스로 규칙을 발견해서 풀어서 기분이 좋았다.
n일때 n-1과 n-2의 개수는 n의 개수만큼 늘어난다는 규칙을 알아내서 굉장히 쉽게 풀었다.
앞으로도 내 스스로 규칙을 찾아서 만드는 문제가 더 많아지도록 노력해야겠다.
*/
