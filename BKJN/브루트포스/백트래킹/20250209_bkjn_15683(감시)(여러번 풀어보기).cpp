#include <iostream>
#include <vector>
using namespace std;

#define MAX 9

int N, M;
int result = 100000000;
int office[MAX][MAX];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
vector <pair<int, int>> cctv;

void checkRange(int r, int c, int dir) {
	dir %= 4;

	while (1) {
		int n_r = r + dr[dir], n_c = c + dc[dir];
		r = n_r, c = n_c;

		if (n_r < 0 || n_r > (N - 1) || n_c < 0 || n_c > (M - 1)) return;
		if (office[n_r][n_c] == 6) return;
		if (office[n_r][n_c] != 0) continue;

		office[n_r][n_c] = -1;
	}
}

void dfs(int idx) {

	if (idx == cctv.size()) {
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (office[i][j] == 0) cnt++;
			}
		}

		result = min(result, cnt);
		return;
	}

	int r = cctv[idx].first, c = cctv[idx].second;
	int tmp[MAX][MAX];

	for (int dir = 0; dir < 4; dir++) {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = office[i][j];
			}
		}

		if (office[r][c] == 1) {
			checkRange(r, c, dir);
		}
		else if (office[r][c] == 2) {
			checkRange(r, c, dir);
			checkRange(r, c, dir + 2);
		}
		else if (office[r][c] == 3) {
			checkRange(r, c, dir);
			checkRange(r, c, dir + 1);
		}
		else if (office[r][c] == 4) {
			checkRange(r, c, dir);
			checkRange(r, c, dir + 1);
			checkRange(r, c, dir + 2);
		}
		else if (office[r][c] == 5) {
			checkRange(r, c, dir);
			checkRange(r, c, dir + 1);
			checkRange(r, c, dir + 2);
			checkRange(r, c, dir + 3);
		}

		dfs(idx + 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> office[i][j];
			if(office[i][j] != 0 && office[i][j] != 6) cctv.push_back({ i, j });
		}
	}

	dfs(0);

	cout << result << "\n";

	return 0;
}
