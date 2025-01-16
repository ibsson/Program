#include <iostream>
using namespace std;

#define MAX 21

int N;
int L[MAX];
int J[MAX];
int dp[102][MAX];

int getResult() {
	
	int max_result = 0;

	for (int i = 1; i < 100; i++) {
		for (int j = 1; j <= N; j++) {
			if (L[j] > i) dp[i][j] = dp[i][j - 1];
			else if (L[j] <= i) dp[i][j] = max(dp[i][j - 1], J[j] + dp[i - L[j]][j - 1]);

			max_result = max(max_result, dp[i][j]);
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
