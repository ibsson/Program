#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10002
using namespace std;

struct Node {
	int num;
	int idx;
};

int index[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> v1(N);
	vector<Node> v2;
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
		index[v1[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v2.push_back({ tmp, index[tmp] });
	}

	vector<int> dp(N, 1);
	vector<int> pre(N, -1);

	int res = 1;
	int last = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (v2[i].idx > v2[j].idx && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				pre[i] = j;
			}
		}
		if (dp[i] > res) {
			res = dp[i];
			last = i;
		}
	}

	vector<int> result;
	while (last != -1) {
		result.push_back(v2[last].num);
		last = pre[last];
	}
	sort(result.begin(), result.end());

	cout << res << '\n';
	for (int x : result) cout << x << ' ';
	cout << '\n';

	return 0;
}
