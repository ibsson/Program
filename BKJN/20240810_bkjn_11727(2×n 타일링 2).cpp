#include <stdio.h>

int main(void) {

	int n = 0, cnt = 0;
	int dp[1002] = { 0 };

	scanf("%d", &n);

	dp[1] = 1, dp[2] = 3;

	for (int i =3; i <= n; i++) {
		dp[i] = (dp[i - 1] + (2 * dp[i - 2])) % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}

/*
이 문제는 11726번에서 변형된 문제다.
역시 dp로 풀었는데, 11726번에서 2x2타일이 추가되어서 1x2를 넣었을 경우, 2x1을 넣었을 경우, 2x2를 넣었을 경우를 고려해주면 된다.
2x3에 2x1을 넣으면 필요한 경우의 수는 dp[2], 1x2를 넣으면 아래에 1x2가 추가되므로 필요한 경우의 수는 dp[1], 2x2를 넣으면 필요한 경우의 수는 dp[1]이므로
점화식은 dp[i] = dp[i - 1] + (2 * dp[i - 2])가 나온다.
*/
