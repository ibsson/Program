#include <iostream>
#include <vector>
#define MAX 10002
using namespace std;

int arr[MAX];
int dp[2][MAX];
bool visited[MAX];
vector <int> v[MAX];

void DFS(int cur) {
	visited[cur] = true;
	dp[0][cur] = 0;
	dp[1][cur] = arr[cur];

	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];

		if (!visited[next]) {
			DFS(next);
			dp[0][cur] += max(dp[0][next], dp[1][next]);
			dp[1][cur] += dp[0][next];
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	int a, b;
	for (int i = 0; i < (N - 1); i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	cout << max(dp[0][1], dp[1][1]) << '\n';

	return 0;
}
