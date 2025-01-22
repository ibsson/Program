#include <stdio.h>

int main(void) {

	int n = 0;
	int dp[1002] = { 0 };

	scanf("%d", &n);

	dp[1] = 1, dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	printf("%d\n", dp[n]);

	return 0;
}

/*
이 문제를 풀다보니 피보나치 수열인 것을 알게 되었는데 왜 그렇게 되는지 이유를 계속 생각했다.

3칸인 타일에 2x1 타일을 넣어보면 남은 2x2칸은 앞에 구해놓은 dp[2]의 경우의 수 인것을 알 수 있다.
그리고 1x2 타일을 넣어보면 아래에 1x2를 넣을 수 밖에 없으므로 2x1칸은 앞에 구해놓은 dp[1]의 경우의 수다.
이렇게 해서 점화식은 dp[i] = dp[i-1] + dp[i-2] 인 것을 알 수 있다.
정확한 설명은 이 링크를 참고했다.
https://blog.naver.com/dev_jumping/223327779710
*/
