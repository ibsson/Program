#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int max_r = 3, max_c = 3;
int arr[101][101];

bool compare(pair<int, int > a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void R() {
	int last_max_c = max_c;
	max_c = 0;

	for (int i = 0; i < max_r; i++) {
		map <int, int> m;
		for (int j = 0; j < last_max_c; j++) {
			if (arr[i][j] != 0) {
				m[arr[i][j]]++;
			}
		}

		vector <pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), compare);

		int idx = 0, len = v.size();
		for (int j = 0; j < len; j++) {
			if (idx == 100) break;

			arr[i][idx] = v[j].first, arr[i][idx + 1] = v[j].second;
			idx += 2;
		}
		for (int j = idx; j < 100; j++) {
			arr[i][j] = 0;
		}
		max_c = max(max_c, idx);
	}
}

void C() {
	int last_max_r = max_r;
	max_r = 0;

	for (int i = 0; i < max_c; i++) {
		map <int, int> m;
		for (int j = 0; j < last_max_r; j++) {
			if (arr[j][i] != 0) {
				m[arr[j][i]]++;
			}
		}

		vector <pair<int, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), compare);

		int idx = 0, len = v.size();
		for (int j = 0; j < len; j++) {
			if (idx == 100) break;

			arr[idx][i] = v[j].first, arr[idx + 1][i] = v[j].second;
			idx += 2;
		}
		for (int j = idx; j < 100; j++) {
			arr[j][i] = 0;
		}
		max_r = max(max_r, idx);
	}
}

int main() {

	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	int t = 0;

	while (1) {
		if (arr[r - 1][c - 1] == k) {
			cout << t << "\n";
			break;
		}

		if (t > 100) {
			cout << "-1\n";
			break;
		}

		if (max_r >= max_c) R();
		else C();

		t++;
	}

	return 0;
}
