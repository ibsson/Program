#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 101
using namespace std;

vector <pair<double, double>> v;
vector <pair<double, pair<int, int>>> star;

int parent[MAX];
double res = 0;

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
	int n;
	cin >> n;

	double a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;

		v.push_back({ a, b });
		parent[i + 1] = i + 1;
	}

	for (int i = 0; i < (n - 1); i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2));

			star.push_back({ dist, {(i + 1), (j + 1)} });
		}
	}

	sort(star.begin(), star.end());

	for (auto i : star) {
		double w = i.first;
		int from = i.second.first, to = i.second.second;

		if (Find(from) == Find(to)) continue;

		Union(from, to);

		res += w;
	}

	cout.precision(3);
	cout << res << '\n';

	return 0;
}
