#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <pair<int, int>> v;

bool Compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main(void) {

	cin >> N;

	int from = 0, to = 0;

	for (int i = 0; i < N; i++) {
		cin >> from >> to;

		v.push_back({ from, to });
	}

	sort(v.begin(), v.end(), Compare);

	int b = v[0].second;
	int cnt = 1;

	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= b) {
			b = v[i].second;
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
