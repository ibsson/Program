#include <iostream>
using namespace std;

const int mod = 1e9 + 9;
unsigned long int dp[100001][4] = { 0 };

int main(void) {

	int T = 0;

	cin >> T;

	int tmp = 0;

	dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0;
	dp[2][1] = 0, dp[2][2] = 1, dp[2][3] = 0;
	dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;

	for (int i = 0; i < T; i++) {
		cin >> tmp;

		for (int j = 4; j <= tmp; j++) {
			dp[j][1] = (dp[j - 1][2] + dp[j - 1][3]) % mod;
			dp[j][2] = (dp[j - 2][1] + dp[j - 2][3]) % mod;
			dp[j][3] = (dp[j - 3][1] + dp[j - 3][2]) % mod;
		}

		cout << (dp[tmp][1] + dp[tmp][2] + dp[tmp][3]) % mod << endl;
	}

	return 0;
}

/*
이 문제는 dp를 풀때 자리수에 관련해서 나눠서 2차원 배열로도 풀 수 있다는 것을 알게해준 문제였다.
앞으로 dp문제를 풀때 시야를 넓힐 수 있을 것 같다.
그리고 마지막에 나머지를 구할때 마지막 자리수 숫자를 기준으로 나눠진 개수들의 나머지를 더한것들을 똑같은 수로 나눠서 나머지를 구해주면
마지막 자리수 숫자를 기준으로 나눠진 개수들의 합을 나눈 나머지와 같다는 것도 알 수 있었다.
*/
