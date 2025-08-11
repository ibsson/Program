#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100002

int N, M, R;
int cnt = 1;
bool Visited[MAX];
int arr[MAX];

vector <int> v[MAX];

void DFS(int x) {
	Visited[x] = true;
	arr[x] = cnt;
	cnt++;

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];

		if (!Visited[next]) {
			Visited[next] = true;
			DFS(next);
		}
	}
}

int main(void) {

	cin >> N >> M >> R;

	int from = 0, to = 0;

	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	DFS(R);

	for (int i = 1; i <= N; i++) {
		if (!Visited[i]) arr[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}
