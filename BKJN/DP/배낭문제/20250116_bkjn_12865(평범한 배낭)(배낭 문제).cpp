#include <iostream>
using namespace std;

int N, K;
int W[102];
int V[102];
int dp[100002][102];

int knapsackProblem() {
	int max_result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i] > j) dp[j][i] = dp[j][i - 1];
			else if (W[i] <= j) dp[j][i] = max(dp[j][i - 1], V[i] + dp[j - W[i]][i - 1]);

			max_result = max(max_result, dp[j][i]);
		}
	}

	return max_result;
}

int main(void) {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	cout << knapsackProblem() << "\n";

	return 0;
}
