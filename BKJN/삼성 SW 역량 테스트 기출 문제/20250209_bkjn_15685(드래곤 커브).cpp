#include <iostream>
#include <vector>
using namespace std;

#define MAX 101

int N, result;
int grid[MAX][MAX];
vector <pair<int, int>> curve[21];


void getResult(int idx, int d, int g) {
	for (int i = 0; i < g; i++) {
		int len = curve[idx].size() - 1;

		for (int j = len; j > 0; j--) {
			int dx = curve[idx][j].first - curve[idx][j - 1].first;
			int dy = curve[idx][j].second - curve[idx][j - 1].second;

			if (dx == 1) {
				curve[idx].push_back({ curve[idx].back().first, curve[idx].back().second - 1 });
			}
			else if (dx == -1) {
				curve[idx].push_back({ curve[idx].back().first, curve[idx].back().second + 1 });
			}
			else if (dy == 1) {
				curve[idx].push_back({ curve[idx].back().first + 1, curve[idx].back().second });
			}
			else if (dy == -1) {
				curve[idx].push_back({ curve[idx].back().first - 1, curve[idx].back().second });
			}
		}
	}
}

int main() {

	cin >> N;

	int x = 0, y = 0, d = 0, g = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		curve[i].push_back({ x, y });
		if (d == 0) curve[i].push_back({ x + 1, y });
		else if(d == 1) curve[i].push_back({ x, y - 1 });
		else if (d == 2) curve[i].push_back({ x - 1, y });
		else if (d == 3) curve[i].push_back({ x, y + 1 });

		getResult(i, d, g);

		for (int j = 0; j < curve[i].size(); j++) {
			grid[curve[i][j].first][curve[i][j].second] = 1;
		}
	}

	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (grid[i][j] == 1) {
				if (grid[i + 1][j] == 1 && grid[i][j + 1] == 1 && grid[i + 1][j + 1] == 1) result++;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
