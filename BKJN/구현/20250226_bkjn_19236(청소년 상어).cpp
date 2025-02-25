#include <iostream>
using namespace std;

struct Fish {
	int r;
	int c;
	int d;
	bool Live;
};

int result;
int grid[4][4];
Fish fish[17];
int dr[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void Input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a = 0, b = 0;
			cin >> a >> b;

			grid[i][j] = a;
			fish[a] = { i, j, b, true };
		}
	}
}

void moveFish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].Live == false) continue;

		int y = fish[i].r, x = fish[i].c, dir = fish[i].d;
		int nr = y + dr[dir], nc = x + dc[dir];
		bool flag = false;

		if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
			if (grid[nr][nc] == 0) {
				flag = true;
				fish[i].r = nr, fish[i].c = nc;
				grid[nr][nc] = i;
				grid[y][x] = 0;
			}
			else if (grid[nr][nc] != -1) {
				flag = true;
				int tmp1 = fish[i].r, tmp2 = fish[i].c;

				fish[i].r = fish[grid[nr][nc]].r, fish[i].c = fish[grid[nr][nc]].c;
				fish[grid[nr][nc]].r = tmp1, fish[grid[nr][nc]].c = tmp2;
				swap(grid[y][x], grid[nr][nc]);
			}
		}

		if (!flag) {
			int ndir = dir + 1;
			if (ndir == 9) ndir = 1;
			int ny = y + dr[ndir], nx = x + dc[ndir];

			while (dir != ndir) {
				if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
					if (grid[ny][nx] == 0) {
						fish[i].r = ny, fish[i].c = nx;
						grid[ny][nx] = i;
						grid[y][x] = 0;
						fish[i].d = ndir;
						break;
					}
					else if (grid[ny][nx] != -1) {
						int tmp1 = fish[i].r, tmp2 = fish[i].c;

						fish[i].r = fish[grid[ny][nx]].r, fish[i].c = fish[grid[ny][nx]].c;
						fish[grid[ny][nx]].r = tmp1, fish[grid[ny][nx]].c = tmp2;
						swap(grid[y][x], grid[ny][nx]);
						fish[i].d = ndir;
						break;
					}
				}
				ndir++;
				if (ndir == 9) ndir = 1;
				ny = y + dr[ndir], nx = x + dc[ndir];
			}
		}
	}
}

void dfs(int y, int x, int dir, int sum) {
	result = max(result, sum);

	int tmp[4][4];
	Fish fish_tmp[17];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = grid[i][j];
		}
	}
	for (int i = 1; i <= 16; i++) {
		fish_tmp[i] = fish[i];
	}

	moveFish();

	for (int i = 1; i <= 3; i++) {
		int nr = y + (dr[dir] * i), nc = x + (dc[dir] * i);

		if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
			if (grid[nr][nc] == 0) continue;

			int num = grid[nr][nc];
			int ndir = fish[num].d;	

			grid[y][x] = 0;
			grid[nr][nc] = -1;
			fish[num].Live = false;

			dfs(nr, nc, ndir, sum + num);

			grid[y][x] = -1;
			grid[nr][nc] = num;
			fish[num].Live = true;
		}
		else {
			break;
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			grid[j][k] = tmp[j][k];
		}
	}
	for (int j = 1; j <= 16; j++) {
		fish[j] = fish_tmp[j];
	}
}

void solution() {
	int num = grid[0][0];
	int dir = fish[num].d;
	fish[num].Live = false;
	grid[0][0] = -1;

	dfs(0, 0, dir, num);

	cout << result << "\n";
}

void solve() {
	Input();
	solution();
}

int main() {

	solve();

	return 0;
}
