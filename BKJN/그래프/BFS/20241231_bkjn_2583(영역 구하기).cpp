#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101

int M, N, K;
int area[MAX][MAX];
int pos[4];
int visited[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int BFS(int i, int j) {
	int extent = 1;

	queue <pair<int, int>> q;
	q.push({ i, j });
	visited[i][j] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];

			if (ny >= 0 && ny < M && nx >= 0 && nx < N) {
				if (!visited[ny][nx] && area[ny][nx] == 0) {
					q.push({ ny, nx });
					visited[ny][nx] = 1;
					extent++;
				}
			}
		}
	}

	return extent;
}

int main(void) {
	
	vector <int> ex;

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> pos[0] >> pos[1] >> pos[2] >> pos[3];

		if (pos[3] < pos[1]) {
			int tmp = pos[3];
			pos[3] = pos[1];
			pos[1] = tmp;
		}

		if (pos[2] < pos[0]) {
			int tmp = pos[2];
			pos[2] = pos[0];
			pos[0] = tmp;
		}

		for (int j = pos[1]; j < pos[3]; j++) {
			for (int k = pos[0]; k < pos[2]; k++) {
				area[j][k] = 1;
			}
		}
	}
	
	int cnt = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && area[i][j] == 0) {
				ex.push_back(BFS(i, j));
				cnt++;
			}
		}
	}

	sort(ex.begin(), ex.end());

	int size = ex.size();

	cout << cnt << "\n";

	for (int i = 0; i < size; i++) {
		cout << ex[i] << " ";
	}
	cout << "\n";

	return 0;
}
