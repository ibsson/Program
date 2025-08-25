#include <iostream>
#include <vector>
#define MAX 10002
using namespace std;

vector <int> v;
int dp[3][MAX]; //안마심, 이번잔만 마심, 연속해서 마심

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	dp[1][0] = v[0];
	int _max = v[0];
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			dp[0][i] = _max;
			dp[1][i] = dp[0][i - 1] + v[i];
			dp[2][i] = dp[1][i - 1] + v[i];
			

			int tmp = max(dp[0][i], dp[1][i]);
			_max = max(tmp, dp[2][i]);
		}
	}

	cout << _max << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

int wine[10002];
int dp[2][10002];

int main(void) {

	int n = 0;

	cin >> n;

	dp[0][0] = 0, dp[0][1] = 0, dp[0][1] = 0, dp[1][1] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
		dp[0][i + 1] = wine[i];
		dp[1][i + 1] = wine[i];
	}

	if (n == 1) {
		cout << wine[1] << endl;
		return 0;
	}

	int result = 0, tmp = 0;

	for (int i = 3; i <= (n + 1); i++) {
		dp[0][i] += max( max(dp[0][i - 2], dp[1][i - 2]), max(dp[0][i - 3], dp[1][i - 3]));
		dp[1][i] += dp[0][i - 1];

		tmp = max(dp[0][i], dp[1][i]);

		if (result < tmp) result = tmp;
	}

	cout << result << endl;

	return 0;
}

/*
스스로 점화식을 만들어내서 풀어냈다. 점점 성장해나가는 것 같다.
그리고 백준 문제에서 96, 98퍼센트 등 끝부분에서 틀리는 경우는 특수한 케이스에서 예외처리를 안했을때 여기서 틀렸다고 나오는것을 알게되었다.
ex) N = 1, 2일때 등
*/
*/
