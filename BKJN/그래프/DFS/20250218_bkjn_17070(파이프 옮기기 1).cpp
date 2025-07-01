#include <iostream>
using namespace std;

#define MAX 17

int N, result;
int grid[MAX][MAX];

void dfs(int sr, int sc, int fr, int fc, int d) {
	if (fr > (N - 1) || fc > (N - 1)) return;

	if (fr == (N - 1) && fc == (N - 1)) {
		result++;
		return;
	}

	switch (d) {
	case 0:
		if (grid[fr][fc + 1] == 0) {
			dfs(fr, fc, fr, fc + 1, 0);
		}
		if (grid[fr][fc + 1] == 0 && grid[fr + 1][fc + 1] == 0 && grid[fr + 1][fc] == 0) {
			dfs(fr, fc, fr + 1, fc + 1, 1);
		}
		break;
	case 1:
		if (grid[fr][fc + 1] == 0) {
			dfs(fr, fc, fr, fc + 1, 0);
		}
		if (grid[fr][fc + 1] == 0 && grid[fr + 1][fc] == 0 && grid[fr + 1][fc + 1] == 0) {
			dfs(fr, fc, fr + 1, fc + 1, 1);
		}
		if (grid[fr + 1][fc] == 0) {
			dfs(fr, fc, fr + 1, fc, 2);
		}
		break;
	case 2:
		if (grid[fr][fc + 1] == 0 && grid[fr + 1][fc] == 0 && grid[fr + 1][fc + 1] == 0) {
			dfs(fr, fc, fr + 1, fc + 1, 1);
		}
		if (grid[fr + 1][fc] == 0) {
			dfs(fr, fc, fr + 1, fc, 2);
		}
		break;
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	dfs(0, 0, 0, 1, 0);

	cout << result << "\n";

	return 0;
}
