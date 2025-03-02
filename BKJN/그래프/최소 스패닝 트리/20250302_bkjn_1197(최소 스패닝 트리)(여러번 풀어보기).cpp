#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

int V, E, ans;
vector <pair<int, pair<int, int>>> v;
int parent[MAX];

int findParent(int x) {
	if (parent[x] != x) return parent[x] = findParent(parent[x]);
	return x;
}

void merge(int a, int b) {
	int x = findParent(a);
	int y = findParent(b);

	if (x != y) {
		if (parent[x] > parent[y]) {
			parent[x] = y;
		}
		else {
			parent[y] = x;
		}
	}
}

int main() {

	cin >> V >> E;

	int A = 0, B = 0, C = 0;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;

		v.push_back({ C, {A, B} });
	}

	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		int w = v[i].first;

		int a = findParent(x);
		int b = findParent(y);

		if (findParent(x) == findParent(y)) continue;

		merge(a, b);
		ans += w;
	}

	cout << ans << "\n";

	return 0;
}
