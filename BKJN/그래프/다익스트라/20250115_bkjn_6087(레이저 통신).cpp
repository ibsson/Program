#include <iostream>
#include <queue>
using namespace std;

#define MAX 102

int H, W;
int start_r, start_c, finish_r, finish_c;
char map[MAX][MAX];
int dir[MAX][MAX];
int _cnt[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dijkstra() {
	queue < pair<int, pair<int, int>>> q;
	q.push({ 0, {start_r, start_c} });
	dir[start_r][start_c] = -1;
	_cnt[start_r][start_c] = 0;

	while (!q.empty()) {
		int r = q.front().second.first;
		int c = q.front().second.second;
		int cnt = q.front().first;
		q.pop();

		if (r == finish_r && c == finish_c) return cnt;

		for (int i = 0; i < 4; i++) {
			int n_r = r + dy[i];
			int n_c = c + dx[i];

			if (n_r >= 0 && n_r < H && n_c >= 0 && n_c < W) {
				if (map[n_r][n_c] != '*') {
					if (cnt < _cnt[n_r][n_c]) {
						if (dir[r][c] == -1) {
							q.push({ cnt, {n_r, n_c} });
							dir[n_r][n_c] = i;
							_cnt[n_r][n_c] = cnt;
						}
						else if (dir[r][c] == 0) {
							if (i == 0) {
								q.push({ cnt, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt;
							}
							else if (i == 1 || i == 3) {
								q.push({ cnt + 1, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt + 1;
							}
						}
						else if (dir[r][c] == 1) {
							if (i == 1) {
								q.push({ cnt, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt;
							}
							else if (i == 0 || i == 2) {
								q.push({ cnt + 1, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt + 1;
							}
						}
						else if (dir[r][c] == 2) {
							if (i == 2) {
								q.push({ cnt, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt;
							}
							else if (i == 1 || i == 3) {
								q.push({ cnt + 1, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt + 1;
							}
						}
						else if (dir[r][c] == 3) {
							if (i == 3) {
								q.push({ cnt, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt;
							}
							else if (i == 0 || i == 2) {
								q.push({ cnt + 1, {n_r, n_c} });
								dir[n_r][n_c] = i;
								_cnt[n_r][n_c] = cnt + 1;
							}
						}
					}
				}
			}
		}
	}
}

int main(void) {

	cin >> W >> H;

	int cnt = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];

			if (cnt == 0 && map[i][j] == 'C') {
				cnt++;
				start_r = i, start_c = j;
			}

			if (cnt == 1 && map[i][j] == 'C') {
				finish_r = i, finish_c = j;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			_cnt[i][j] = 100;
		}
	}

	cout << dijkstra() << "\n";

	return 0;
}
