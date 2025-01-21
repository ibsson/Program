#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 101

int N;
int G[MAX][MAX];
int visited[MAX];
int result[MAX][MAX];
vector <pair<int, int>> v;

void bfs(int r, int c) {
	queue <int> q;
	q.push(r);

	while (!q.empty()) {
		int cur_r = q.front();
		q.pop();

		for (int i = 0; i < N; i++) {
			if (G[cur_r][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		result[r][i] = visited[i];
	}
}

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> G[i][j];
			v.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		memset(visited, false, sizeof(visited));

		bfs(v[i].first, v[i].second);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
