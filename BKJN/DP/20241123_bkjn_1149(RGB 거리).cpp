#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0], dp[0][1] = arr[0][1], dp[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	int res = min(dp[N - 1][0], dp[N - 1][1]);
	res = min(res, dp[N - 1][2]);

	cout << res << '\n';

	return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1000000
int N;
int color[1001][3];
int dp[1001][3];
int ans = MAX;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}

	for (int RGB = 0; RGB < 3; RGB++) {
		for (int i = 0; i < 3; i++) {
			if (i == RGB) dp[0][i] = color[0][i];
			else dp[0][i] = MAX;
		}

		for (int i = 1; i < N; i++) {
			dp[i][0] = color[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = color[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = color[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i < 3; i++) {
			ans = min(ans, dp[N - 1][i]);
		}
	}

	cout << ans << "\n";

	return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][3] = {0};

int Get_Result(int n);

int main(void) {

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i][j];
		}
	}

	cout << Get_Result(N) << endl;

	return 0;
}

int Get_Result(int n) {

	for (int i = 1; i < n; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}

	int result = min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] });

	return result;
}
*/

/*
처음에는 재귀함수로 풀어봤는데 역시나 시간초과가 났다.
그래서 dp로 풀었더니 맞았다.
이 문제에서 min함수에서 인수를 한번에 3개를 비교하는 방법을 알게되었다.
*/
*/
