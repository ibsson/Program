#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 100002
#define INF 1000000000

vector <int> bomb;
long long int dp[2][MAX]; //0일때, L일때

long long int solution(int N, int L) {
	dp[0][0] = bomb[0] * 2;
	dp[1][0] = L;

	for (int i = 1; i < N; i++) {
		dp[0][i] = min(dp[0][i - 1] + (bomb[i] * 2), dp[1][i - 1] + L);
		dp[1][i] = min(dp[0][i - 1] + L, dp[1][i - 1] + ((L - bomb[i]) * 2));
	}

	return min(dp[0][N - 1], dp[1][N - 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	int N, L;
	for (int i = 1; i <= T; i++) {
		cin >> N >> L;

		int tmp;
		for(int j = 0; j < N; j++) {
			cin >> tmp;
			bomb.push_back(tmp);
		}

		cout << "Case #" << i << '\n';
		cout << solution(N, L) << '\n';

		memset(dp, 0, sizeof(dp));
		bomb.clear();
	}

	return 0;
}
