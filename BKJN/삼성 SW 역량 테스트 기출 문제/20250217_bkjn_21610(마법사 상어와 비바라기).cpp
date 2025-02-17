#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 51

int N, M, result;
int grid[MAX][MAX];
bool chk[MAX][MAX];
int dr[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
vector <pair<int, int>> cloud;

void arrangeGrid(int dir, int dis) {
	int len = cloud.size();

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < dis; j++) {
			int nr = cloud[i].first + dr[dir - 1], nc = cloud[i].second + dc[dir - 1];
			
			if (nr < 0) nr = (N - 1);
			if (nr > (N - 1)) nr = 0;
			if (nc < 0) nc = (N - 1);
			if (nc > (N - 1)) nc = 0;

			cloud[i] = { nr, nc };
		}
	}

	for (int i = 0; i < len; i++) {
		int r = cloud[i].first, c = cloud[i].second;
		grid[r][c]++;
	}

	for (int i = 0; i < len; i++) {
		int r = cloud[i].first, c = cloud[i].second;
		for (int j = 1; j < 8; j += 2) {
			int nr = r + dr[j], nc = c + dc[j];
			
			if (nr < 0 || nr >(N - 1) || nc < 0 || nc >(N - 1)) continue;

			if (grid[nr][nc] > 0) grid[r][c]++;
		}
		chk[r][c] = true;
	}

	cloud.clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] >= 2 && !chk[i][j]) {
				cloud.push_back({ i, j });
				grid[i][j] -= 2;

			}
		}
	}

	memset(chk, false, sizeof(chk));
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	cloud.push_back({ N - 1, 0 }), cloud.push_back({ N - 1, 1 }), cloud.push_back({ N - 2, 0 }), cloud.push_back({ N - 2, 1 });

	int d = 0, s = 0;
	for (int i = 0; i < M; i++) {
		cin >> d >> s;

		arrangeGrid(d, s);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] > 0) {
				result += grid[i][j];
			}
		}
	}

	cout << result << "\n";

	return 0;
}
