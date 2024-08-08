#include <stdio.h>

int main(void) {

	int N = 0;
	int stair[301] = { 0 };
	int dp[301] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &stair[i]);
	}

	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	
	if (stair[0] + stair[2] > stair[1] + stair[2]) dp[2] = stair[0] + stair[2];
	else dp[2] = stair[1] + stair[2];

	for (int i = 3; i < N; i++) {
		if ((dp[i - 2] + stair[i]) > dp[i - 3] + stair[i - 1] + stair[i]) {
			dp[i] = dp[i - 2] + stair[i];
		}
		else dp[i] = dp[i - 3] + stair[i - 1] + stair[i];
	}

	printf("%d\n", dp[N - 1]);

	return 0;
}

/*
이 문제는 계속 생각해보다가 모르겠어서 검색을 해서 풀었다.
아직까지는 dp문제를 풀때 아이디어를 떠올리는 것이 쉽지 않은 것 같다.
특히 점화식을 만들어내는것이 쉽지 않은 것 같다.
이 문제도 계속해서 경우의수를 고려해보면 점화식이 나오는데, 나는 경우의 수를 나열해보지도 않았다.
이 부분에서 반성을 하게 되었다.
앞으로 dp문제를 풀때 경우의 수를 나누는 것을 적어도 시도는 해봐야겠다고 다짐했다.
*/
