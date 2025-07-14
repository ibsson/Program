#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX 25

int N, M, _min = INT_MAX;
char map[MAX][MAX];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void dfs(int ay, int ax, int by, int bx, int cnt) {
	if (cnt > 10) return;

	bool a_out = (ay < 1 || ay > N || ax < 1 || ax > M);
	bool b_out = (by < 1 || by > N || bx < 1 || bx > M);

	if (a_out && b_out) return;
	if (a_out || b_out) {
		_min = min(_min, cnt);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int n_ay = ay + dir[i][0];
		int n_ax = ax + dir[i][1];
		int n_by = by + dir[i][0];
		int n_bx = bx + dir[i][1];

		if (map[n_ay][n_ax] == '#') {
			n_ay = ay;
			n_ax = ax;
		}
		if (map[n_by][n_bx] == '#') {
			n_by = by;
			n_bx = bx;
		}

		dfs(n_ay, n_ax, n_by, n_bx, cnt + 1);
	}
}

int main(void) {

	vector <int> y;
	vector <int> x;

	cin >> N >> M;

	for (int i = 0; i <= (N + 1); i++) {
		map[i][0] = 'X';
		map[i][M + 1] = 'X';
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = ' ';
		}
	}
	for (int i = 0; i <= (M + 1); i++) {
		map[0][i] = 'X';
		map[N + 1][i] = 'X';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			map[i + 1][j + 1] = 'X';

			if (map[i][j] == 'o') {
				y.push_back(i);
				x.push_back(j);
			}
		}
	}

	dfs(y[0], x[0], y[1], x[1], 0);

	if (_min == INT_MAX) _min = -1;
	
	cout << _min << "\n";

	return 0;
}
