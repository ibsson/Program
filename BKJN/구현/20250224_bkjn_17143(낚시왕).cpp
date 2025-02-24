#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 102

struct shark {
	int r;
	int c;
	int s; //속력
	int d; //이동방향
	int z; //크기
};

int R, C, M, result;
vector <shark> grid[MAX][MAX];
vector <shark> v;

bool compare(shark a, shark b) {
	return a.z > b.z;
}

void moveShark() {
	sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < v.size(); i++) {
		int tmp = v[i].s;

		while (tmp > 0) {
			if (v[i].d == 1) {
				if (v[i].r - tmp < 1) {
					tmp -= (v[i].r - 1);
					v[i].r = 1;
					v[i].d = 2;
				}
				else {
					v[i].r -= tmp;
					tmp -= tmp;
				}
			}
			else if (v[i].d == 2) {
				if (v[i].r + tmp > R) {
					tmp -= (R - v[i].r);
					v[i].r = R;
					v[i].d = 1;
				}
				else {
					v[i].r += tmp;
					tmp -= tmp;
				}
			}
			else if (v[i].d == 3) {
				if (v[i].c + tmp > C) {
					tmp -= (C - v[i].c);
					v[i].c = C;
					v[i].d = 4;
				}
				else {
					v[i].c += tmp;
					tmp -= tmp;
				}
			}
			if (v[i].d == 4) {
				if (v[i].c - tmp < 1) {
					tmp -= (v[i].c - 1);
					v[i].c = 1;
					v[i].d = 3;
				}
				else {
					v[i].c -= tmp;
					tmp -= tmp;
				}
			}
		}

		if (grid[v[i].r][v[i].c].size() == 0) {
			grid[v[i].r][v[i].c].push_back(v[i]);
		}
	}

 	v.clear();
}

void catchShark(int i) {
	for (int j = 1; j <= R; j++) {
		if (grid[j][i].size() != 0) {
			result += grid[j][i][0].z;
			grid[j][i].clear();
			break;
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (grid[i][j].size() == 1) {
				v.push_back(grid[i][j][0]);
				grid[i][j].clear();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		shark tmp;
		cin >> tmp.r >> tmp.c >> tmp.s >> tmp.d >> tmp.z;
		grid[tmp.r][tmp.c].push_back(tmp);
	}

	for (int i = 1; i <= C; i++) {
		catchShark(i);
		moveShark();
	}

	cout << result << "\n";

	return 0;
}
