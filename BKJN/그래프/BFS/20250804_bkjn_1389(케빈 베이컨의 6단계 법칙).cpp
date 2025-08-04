#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define MAX 101
using namespace std;

struct Node {
	int idx, distance;
};

vector <int> v[MAX];
int dist[MAX];
bool visited[MAX];

int tmp = INT_MAX;

void BFS(int x) {
	queue <Node> q;
	q.push({x, 0});
	visited[x] = true;

	while (!q.empty()) {
		int a = q.front().idx, b = q.front().distance;
		q.pop();

		dist[a] = min(dist[a], b);

		for (int i = 0; i < v[a].size(); i++) {
			if (!visited[v[a][i]]) {
				q.push({ v[a][i], b + 1});
				visited[v[a][i]] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	int res = INT_MAX, idx = -1, sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[j] = INT_MAX;
			visited[j] = false;
		}
		
		BFS(i);

		sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += dist[j];
		}

		if (res > sum) {
			res = sum;
			idx = i;
		}
	}

	cout << idx << '\n';

	return 0;
}
