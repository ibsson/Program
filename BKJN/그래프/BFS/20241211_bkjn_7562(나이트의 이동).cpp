#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int Move[8][2] = { {1, -2}, {2, -1},{2, 1},{1, 2},{-1, 2},{-2, 1}, {-2, -1},{-1, -2} };
int Map[301][301];
int Visited[301][301];
int start_y, start_x;
int finish_y, finish_x;
int l = 0;

void BFS(int y, int x);

int main(void) {

	int T = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> l;

		cin >> start_x >> start_y;
		cin >> finish_x >> finish_y;

		BFS(start_y, start_x);

		memset(Map, 0, sizeof(Map));
		memset(Visited, 0, sizeof(Visited));
	}

	return 0;
}

void BFS(int y, int x) {

	queue <pair<int, int>> q;
	q.push({ y, x });
	Visited[y][x] = 1;

	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();
		
		if (_y == finish_y && _x == finish_x) {
			cout << Map[_y][_x] << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		for (int i = 0; i < 8; i++) {
			int n_y = _y + Move[i][0];
			int n_x = _x + Move[i][1];

			if (n_y >= 0 && n_y < l && n_x >= 0 && n_x < l && Visited[n_y][n_x] == 0) {
				q.push({ n_y, n_x });
				Visited[n_y][n_x] = 1;
				Map[n_y][n_x] = Map[_y][_x] + 1;
			}
		}
	}
}

/*
이 문제를 통해 BFS로 구하는 경로는 최단경로라는 것을 알게 되었다.
*/
