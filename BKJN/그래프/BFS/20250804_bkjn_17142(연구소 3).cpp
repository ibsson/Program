#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define MAX 51
using namespace std;

struct Node1 {
	int y, x;
};
struct Node2 {
	int y, x, time;
};

int N, M;
int map[MAX][MAX];
bool selected[MAX];
bool visited[MAX][MAX];
vector<Node1> tmp;
vector<Node1> v;
queue<Node2> q;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int res = INT_MAX;

int BFS() {
	bool localVisited[MAX][MAX] = { false };
	queue<Node2> q;

	for (int i = 0; i < M; i++) {
		int y = tmp[i].y, x = tmp[i].x;
		q.push({ y, x, 0 });
		localVisited[y][x] = true;
	}

	int time = 0;

	while (!q.empty()) {
		int y = q.front().y, x = q.front().x, t = q.front().time;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (map[ny][nx] == 1 || localVisited[ny][nx]) continue;

			localVisited[ny][nx] = true;
			q.push({ ny, nx, t + 1 });
			if (map[ny][nx] == 0) time = max(time, t + 1);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && !localVisited[i][j]) return -1;
		}
	}

	return time;
}

void selectVirus(int cnt, int start) {
	if (cnt == M) {
		int t = BFS();
		if (t != -1) res = min(res, t);
		return;
	}

	for (int i = start; i < v.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;
			tmp.push_back(v[i]);
			selectVirus(cnt + 1, i + 1);
			tmp.pop_back();
			selected[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}

	selectVirus(0, 0);

	if (res == INT_MAX) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}
