#include <iostream>
using namespace std;

#define MAX 21

int N;
int L[MAX];
int J[MAX];
int dp[102][MAX];

int getResult() {
	
	int max_result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 100; j++) {
			if (L[i] > j) dp[j][i] = dp[j][i - 1];
			else if (L[i] <= j) dp[j][i] = max(dp[j][i - 1], J[i] + dp[j - L[i]][i - 1]);

			max_result = max(max_result, dp[j][i]);
		}
	}

	return max_result;
}

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> L[i];
	}

	for (int i = 1; i <= N; i++) {
		cin >> J[i];
	}

	cout << getResult() << "\n";

	return 0;
}
