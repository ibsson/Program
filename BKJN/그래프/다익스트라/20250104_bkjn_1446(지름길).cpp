#include <iostream>
#include <vector>
using namespace std;

#define MAX 10001

int N, D;
vector <pair<int, int>> v[MAX];
int map[MAX];

int main(void) {

	cin >> N >> D;

	int from = 0, to = 0, w = 0;

	for (int i = 0; i < N; i++) {
		cin >> from >> to >> w;

		v[to].push_back({ from, w });
	}

	fill(map, map + (D + 1), MAX);

	map[0] = 0;

	for (int i = 1; i <= D; i++) {
		if (v[i].size() == 0) {
			map[i] = map[i - 1] + 1;
		}
		else {
			for (int j = 0; j < v[i].size(); j++) {
				map[i] = min(map[i], min(map[i - 1] + 1, map[v[i][j].first] + v[i][j].second));
			}
		}
	}

	cout << map[D] << "\n";

	return 0;
}
