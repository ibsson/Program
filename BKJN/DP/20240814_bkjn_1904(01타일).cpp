#include <stdio.h>

int dp[1000002] = { 0 };

void Get_Tile_Cnt(int N) {

	dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
}

int main(void) {

	int N = 0;

	scanf("%d", &N);

	Get_Tile_Cnt(N);

	printf("%d\n", dp[N]);

	return 0;
}

/*
이 문제는 dp로 풀었다.
내 스스로 규칙을 찾아내서 풀어냈다.
1부터 늘려가면서 개수를 세보니 피보나치수열의 규칙이 나오는 것을 알게되었다.
규칙을 찾으니 쉽게 풀었다.
*/
