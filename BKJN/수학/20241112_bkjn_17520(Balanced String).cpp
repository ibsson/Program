#include <iostream>
using namespace std;

int dp[100001] = { 0 };

int main(void) {

	int n = 0;

	cin >> n;

	dp[1] = 2, dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (2 * dp[i - 2]) % 16769023;
	}

	cout << dp[n] << endl;

	return 0;
}

/*
이 문제는 내 스스로 점화식을 만들어서 풀었다.
계속 쓰면서 규칙을 찾다보면 규칙은 나온다.
앞으로 문제를 풀때도 이런 마음가짐으로 최대한 끝까지 규칙을 찾고 점화식을 만들어서 풀어봐야겠다.
*/
