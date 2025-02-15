#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int cnt;
char field[13][7];
int chk[13][7];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

void bfs(int r, int c, int num) {
	queue <pair<int, int>> q;
	q.push({ r, c });
	chk[r][c] = num;

	char color = field[r][c];
	cnt = 1;

	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i], nc = cc + dc[i];

			if (nr < 0 || nr > 11 || nc < 0 || nc > 5) continue;

			if (field[nr][nc] == color && chk[nr][nc] == 0) {
				q.push({ nr, nc });
				chk[nr][nc] = num;
				cnt++;
			}
		}
	}
}

void arrangeMap() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (field[i][j] == '0') {
				int cnt_zero = 0, tmp = i;

				while (1) {
					if (tmp > 11 || field[tmp][j] != '0') break;

					tmp++;
					cnt_zero++;
				}

				for (int k = i - 1; k >= 0; k--) {
					field[k + cnt_zero][j] = field[k][j];
					field[k][j] = '.';
				}
			}
		}
	}
}

int main() {

	for (int i = 0; i < 12; i++) {
		cin >> field[i];
	}

	int sequence = 0;

	while (1) {
		int num = 1;
		bool chk_finish = true;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (field[i][j] != '.' && chk[i][j] == 0) {
					bfs(i, j, num);

					if (cnt >= 4) {
						for (int k = 0; k < 12; k++) {
							for (int l = 0; l < 6; l++) {
								if (chk[k][l] == num) field[k][l] = '0';
							}
						}

						chk_finish = false;
					}

					num++;
				}
			}
		}
		if (chk_finish) break;
		else {
			sequence++;
			arrangeMap();
		}

		memset(chk, 0, sizeof(chk));
	}

	cout << sequence << "\n";

	return 0;
}
