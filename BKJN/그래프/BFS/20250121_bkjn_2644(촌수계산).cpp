#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int n, m;
vector <int> v[MAX];
bool visited[MAX];

int bfs(int start, int finish) {
	queue <pair<int, int>> q;
	q.push({ start, 0 });
	visited[start] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur_x == finish) return cnt;

		for (int i = 0; i < v[cur_x].size(); i++) {
			int next_x = v[cur_x][i];

			if (visited[next_x]) continue;

			q.push({ next_x, cnt + 1 });
			visited[next_x] = true;
		}
	}

	return -1;
}

int main(void) {

	cin >> n;

	int t_from = 0, t_to = 0;

	cin >> t_from >> t_to;
	cin >> m;

	int from = 0, to = 0;

	for (int i = 0; i < m; i++) {
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	cout << bfs(t_from, t_to) << "\n";

	return 0;
}
