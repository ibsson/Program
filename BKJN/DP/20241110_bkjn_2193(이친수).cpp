#include <iostream>
using namespace std;

long long int dp[2][92];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	
	long long int res = dp[0][N] + dp[1][N];
	cout << res << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	long long int pibo[91] = { 0 };

	cin >> N;

	pibo[0] = 1, pibo[1] = 1;

	for (int i = 2; i < N; i++) {
		pibo[i] = pibo[i - 1] + pibo[i - 2];
	}

	cout << pibo[N - 1] << "\n";

	return 0;
}
*/
