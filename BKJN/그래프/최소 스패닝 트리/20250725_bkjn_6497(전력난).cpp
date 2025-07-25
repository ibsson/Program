#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

int parent[MAX];

int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	while (true) {
		vector <pair<int, pair<int, int>>> v;
		int res = 0;

		cin >> m >> n;

		if (m == 0 && n == 0) break;

		int x, y, z;
		long long int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;

			sum += z;

			v.push_back({ z, {x, y} });
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < n; i++) {
			int w = v[i].first, from = v[i].second.first, to = v[i].second.second;

			if (Find(from) == Find(to)) continue;

			Union(from, to);

			res += w;
		}

		cout << sum - res << '\n';

		v.clear();
		res = 0;
	}

	return 0;
}
