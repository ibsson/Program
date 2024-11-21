#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	int num[1002] = { 0 };
	int dp[1002] = { 0 };

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = num[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = (i - 1); j >= i / 2; j--) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}

/*
이 코드는 내가 스스로 점화식을 찾아서 풀어냈다.
점점 dp문제를 푸는것에 감을 찾아가는 것 같다.
*/
