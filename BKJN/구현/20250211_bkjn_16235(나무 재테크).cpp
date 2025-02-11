#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 12

int N, M, K;
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int A[MAX][MAX];
int ground[MAX][MAX];
vector <int> map[MAX][MAX];
queue <pair<int, pair<int, int>>> dead_tree;

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(map[i][j].begin(), map[i][j].end());
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				int age = map[i][j][k];
				if (age <= ground[i][j]) {
					ground[i][j] -= age;
					map[i][j][k]++;
				}
				else {
					dead_tree.push({ age, {i, j} });
					map[i][j].erase(map[i][j].begin() + k);
					k--;
				}
			}
		}
	}
}

void summer() {
	while (!dead_tree.empty()) {
		int age = dead_tree.front().first, r = dead_tree.front().second.first, c = dead_tree.front().second.second;
		dead_tree.pop();

		ground[r][c] += age / 2;
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < map[i][j].size(); k++) {
				int age = map[i][j][k];

				if (age % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int nr = i + dr[l], nc = j + dc[l];

						if (nr < 1 || nr > N || nc < 1 || nc > N) continue;

						map[nr][nc].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ground[i][j] += A[i][j];
		}
	}
}

int main() {

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ground[i][j] = 5;
		}
	}

	int x = 0, y = 0, age = 0;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> age;
		map[x][y].push_back(age);
	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result += map[i][j].size();
		}
	}

	cout << result << "\n";
	
	return 0;
}
