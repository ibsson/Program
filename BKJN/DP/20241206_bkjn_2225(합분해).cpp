#include <iostream>
#define MAX 202
#define MOD 1000000000
using namespace std;

int dp[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1 && j == 1) dp[i][j] = 1;
			else if (j == 1) dp[i][j] = i;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[K][N] << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

int N, K;
long long int result;
long long int dp[202][202];
const int mod = 1e9;

int main(void) {

	cin >> N >> K;

	dp[1][1] = 1;

	for (int i = 1; i <= (N + 1); i++) {
		dp[2][i] = 1;
	}

	if (K == 1) {
		result = 1;
		cout << result << "\n";
		
		return 0;
	}
	else if (K == 2) {
		result = N + 1;
		cout << result << "\n";

		return 0;
	}

	for (int i = 3; i <= K; i++) {
		for (int j = 1; j <= (N + 1); j++) {
			for (int m = j; m <= (N + 1); m++) {
				dp[i][j] += ((dp[i - 1][m]) % mod);
			}
		}
	}

	for (int i = 1; i <= (N + 1); i++) {
		result += dp[K][i];
		result %= mod;
	}

	cout << result << "\n";

	return 0;
}

/*
내 스스로 풀어낸 문제라 뿌듯하다.
처음으로 골드티어 문제를 온전히 내 힘으로 풀어냈다.
계속 쓰면서 규칙을 찾다보니 점화식을 찾을 수 있었다.
시간이 오래 걸리더라도 계속 써보면서 규칙을 찾아보면 결국에는 나온다고 생각했고 앞으로 이걸 잊지 말고 계속 이렇게 풀어야겠다고 생각했다.
*/
*/
