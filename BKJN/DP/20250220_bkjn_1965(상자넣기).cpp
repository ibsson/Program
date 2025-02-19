#include <iostream>
using namespace std;

#define MAX 1001

int N, result;
int arr[MAX];
int dp[MAX];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	dp[0] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	cout << result << "\n";

	return 0;
}
