#include <iostream>
#include <queue>
using namespace std;

#define MAX 601

string str[601];
bool visited[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
queue <pair<int, int>> Q;

int BFS(int N, int M) {
	int cnt = 0;

	visited[N][M] = true;

	while (!Q.empty()) {
		int y = Q.front().first, x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			
			if (!visited[ny][nx] && str[ny][nx] != 'X') {
				if (str[ny][nx] == 'P') cnt++;

				visited[ny][nx] = true;
				Q.push({ ny, nx });
			}
		}
	}

	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		for (int j = 0; j < M; j++) {
			if (str[i][j] == 'I') Q.push({i, j});
		}
	}

	int res = BFS(N, M);

	if (res == 0) cout << "TT\n";
	else cout << res << "\n";

	return 0;
}
