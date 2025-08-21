#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int num[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	dp[1] = num[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = num[i];

		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[i - j] + num[j]);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}
