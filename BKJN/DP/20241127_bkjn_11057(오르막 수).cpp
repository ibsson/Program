#include <iostream>
using namespace std;

int dp[1001][10];

int main(void) {

	int N = 0, mod = 10007;

	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += (dp[i - 1][k]) % mod;
				dp[i][j] %= mod;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < 10; i++) {
		result += (dp[N][i]) % mod;
	}

	cout << (result) % mod << endl;

	return 0;
}

/*
이 문제는 스스로 규칙을 찾아서 점화식을 만들었다.
조금 시행착오가 있었지만 그래도 풀어냈다.
문제를 풀때 정말 작은 차이로 문제가 발생할때가 많다.
이런일을 방지하기 위해서 더 섬세하게 생각해서 문제를 풀어나가야겠다.
*/
