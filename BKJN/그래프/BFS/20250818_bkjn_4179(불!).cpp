#include <iostream>
#include <string>
#include <queue>
#define MAX 1001
#define INF 1e9
using namespace std;

struct Node {
	int y, x;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0 ,1 };
int R, C;
bool visited[MAX][MAX];
string Map[MAX];
int Fire[MAX][MAX];
int Man[MAX][MAX];
queue <Node> q;
queue <Node> man;

void makeFire() {
	while (!q.empty()) {
		int y = q.front().y, x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (Map[ny][nx] == '#') continue;

			if (Fire[ny][nx] > Fire[y][x] + 1) {
				Fire[ny][nx] = Fire[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int moveMan(int a, int b) {
	visited[a][b] = true;

	while (!man.empty()) {
		int y = man.front().y, x = man.front().x;
		man.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C) return Man[y][x] + 1;
			if (Map[ny][nx] == '#') continue;
			if (visited[ny][nx]) continue;

			if (Fire[ny][nx] > Man[y][x] + 1) {
				Man[ny][nx] = Man[y][x] + 1;
				man.push({ ny, nx });
				visited[ny][nx] = true;
			} 
		}
	}

	return INF;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			Fire[i][j] = INF;
			Man[i][j] = INF;
		}
	}

	for (int i = 0; i < R; i++) {
		cin >> Map[i];
	}

	int a = 0, b = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Map[i][j] == 'F') {
				q.push({ i, j });
				Fire[i][j] = 0;
			}

			if (Map[i][j] == 'J') {
				a = i, b = j;
				man.push({ i, j });
				Man[i][j] = 0;
			}
		}
	}

	makeFire();

	int res = moveMan(a, b);
	if (res == INF) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << res << '\n';
	}

	return 0;
}
