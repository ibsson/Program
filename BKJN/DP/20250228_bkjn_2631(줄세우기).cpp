#include <iostream>
using namespace std;

int N, result;
int line[201];
int dp[201];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> line[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (line[i] > line[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

			result = max(result, dp[i]);
		}
	}

	cout << N - result << "\n";
	
	return 0;
}
