#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100002

int N, M, R;
vector <int> v[MAX];
int arr[MAX];
bool Visited[MAX];
int cnt = 1;

void BFS(int x) {
	queue <int> q;
	q.push(x);
	Visited[x] = true;

	while (!q.empty()) {
		int _x = q.front();
		arr[_x] = cnt;
		cnt++;
		q.pop();

		for (int i = 0; i < v[_x].size(); i++) {
			int next = v[_x][i];

			if (!Visited[next]) {
				q.push(next);
				Visited[next] = true;
			}
		}
	}
}

bool Compare(int a, int  b) {
	return a > b;
}

int main(void) {

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		int from = 0, to = 0;

		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), Compare);
	}

	BFS(R);

	for (int i = 1; i <= N; i++) {
		if (!Visited[i]) {
			arr[i] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}
