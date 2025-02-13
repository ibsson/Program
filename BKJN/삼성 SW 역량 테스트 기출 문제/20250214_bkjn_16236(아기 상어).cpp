#include <iostream>
#include <string.h>
using namespace std;

#define MAX 401

int N;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
int arr[MAX][6];
int map[21][21];
int chk_like[21][21];
int chk_empty[21][21];
int order[MAX];

void getResult() {
	for (int a = 0; a < N * N; a++) {
		memset(chk_like, 0, sizeof(chk_like));
		memset(chk_empty, 0, sizeof(chk_empty));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int nr = i + dr[k], nc = j + dc[k];

						if (nr < 0 || nr > (N - 1) || nc < 0 || nc > (N - 1)) continue;

						if (map[nr][nc] != 0) {
							for (int l = 1; l <= 4; l++) {
								if (arr[a][l] == map[nr][nc]) {
									chk_like[i][j]++;
								}
							}
						}
						else {
							chk_empty[i][j]++;
						}
					}
				}
			}
		}

		pair<pair<int, int>, pair<int, int>> _max;
		_max = { {-1, -1}, {0, 0} };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					if (chk_like[i][j] > _max.first.first) _max = { {chk_like[i][j], chk_empty[i][j]}, {i, j} };

					if (_max.first.first == chk_like[i][j]) {
						if (_max.first.second < chk_empty[i][j]) _max = { {chk_like[i][j], chk_empty[i][j]}, {i, j} };
					}
				}
			}
		}

		map[_max.second.first][_max.second.second] = arr[a][0];
	}
}

int main() {

	cin >> N;

	int x = 0;
	for (int i = 0; i < N * N; i++) {
		for (int j = 0; j <= 4; j++) {
			cin >> arr[i][j];

			order[arr[i][0]] = i;
		}
	}

	getResult();

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int idx = order[map[i][j]], cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k], nc = j + dc[k];

				if (nr < 0 || nr >(N - 1) || nc < 0 || nc >(N - 1)) continue;

				for (int l = 1; l <= 4; l++) {
					if (map[nr][nc] == arr[idx][l]) cnt++;
				}
			}

			if (cnt == 0) result += 0;
			else if (cnt == 1) result += 1;
			else if (cnt == 2) result += 10;
			else if (cnt == 3) result += 100;
			else if (cnt == 4) result += 1000;
		}
	}

	cout << result << "\n";

	return 0;
}
