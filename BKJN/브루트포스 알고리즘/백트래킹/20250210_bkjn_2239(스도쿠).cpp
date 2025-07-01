#include <iostream>
#include <vector>
using namespace std;

int sudoku[10][10];
bool chk_finish;
vector <pair<int, int>> v;

void dfs(int idx) {
	if (idx == v.size()) {
		chk_finish = true;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j];
			}
			cout << "\n";
		}

		return;
	}

	int r = v[idx].first, c = v[idx].second;
	int r_range = r / 3, c_range = c / 3;

	for (int i = 1; i <= 9; i++) {
		bool chk = true;
		for (int j = 0; j < 9; j++) {
			if (sudoku[r][j] == i) {
				chk = false;
				break;
			}
		}

		for (int j = 0; j < 9; j++) {
			if (sudoku[j][c] == i) {
				chk = false;
				break;
			}
		}

		for (int j = r_range * 3; j < (r_range * 3) + 3; j++) {
			for (int k = c_range * 3; k < (c_range * 3) + 3; k++) {
				if (sudoku[j][k] == i) {
					chk = false;
					break;
				}
			}
		}

		if (chk) {
			sudoku[v[idx].first][v[idx].second] = i;
			dfs(idx + 1);
			if (chk_finish) return;
			sudoku[v[idx].first][v[idx].second] = 0;
		}
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		string tmp;

		cin >> tmp;

		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = tmp[j] - '0';

			if (sudoku[i][j] == 0) v.push_back({ i, j });
		}
	}

	dfs(0);

	return 0;
}
