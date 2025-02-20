#include <iostream>
using namespace std;

#define MAX 1000001

int X;
int dp[MAX];

int main() {

	cin >> X;

	dp[1] = 0;

	for (int i = 2; i <= X; i++) {
		int tmp = dp[i - 1] + 1;

		if (i % 2 == 0) {
			if (tmp > dp[i / 2] + 1) {
				tmp = dp[i / 2] + 1;
			}
		}

		if (i % 3 == 0) {
			if (tmp > dp[i / 3] + 1) {
				tmp = dp[i / 3] + 1;
			}
		}

		dp[i] = tmp;
	}

	cout << dp[X] << "\n";

	int cur = X;
	while (1) {
		cout << cur << " ";

		if (cur == 1) break;

		if (dp[cur] == dp[cur - 1] + 1) cur -= 1;
		else if (cur % 2 == 0 && dp[cur] == dp[cur / 2] + 1) cur /= 2;
		else if (cur % 3 == 0 && dp[cur] == dp[cur / 3] + 1) cur /= 3;
	}

	return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001

int X;
int dp[MAX];
vector <int> v[MAX];

int main() {
	
	cin >> X;

	dp[1] = 0;
	v[1].push_back(1);

	for (int i = 2; i <= X; i++) {
		int tmp = dp[i - 1] + 1;
		int idx = i - 1;

		if (i % 2 == 0) {
			if (tmp > dp[i / 2] + 1) {
				tmp = dp[i / 2] + 1;
				idx = i / 2;
			}
		}

		if (i % 3 == 0) {
			if (tmp > dp[i / 3] + 1) {
				tmp = dp[i / 3] + 1;
				idx = i / 3;
			}
		}

		dp[i] = tmp;

		for (int j = 0; j < v[idx].size(); j++) {
			v[i].push_back(v[idx][j]);
		}
		v[i].push_back(i);
	}

	cout << dp[X] << "\n";
	for (int i = (v[X].size() - 1); i >= 0; i--) {
		cout << v[X][i] << " ";
	}

	return 0;
}
*/
