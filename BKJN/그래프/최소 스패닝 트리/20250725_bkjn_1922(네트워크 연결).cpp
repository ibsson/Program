#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector <pair<int, pair<int, int>>> v;
int parent[MAX];
int res = 0;

int Find(int x) {
	if (parent[x] == x) return x;
	return x = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	parent[x] = y;
}

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int w = v[i].first, from = v[i].second.first, to = v[i].second.second;

		int tmp1 = Find(from), tmp2 = Find(to);

		if (tmp1 == tmp2) continue;

		Union(from, to);
		res += w;
	}

	cout << res << '\n';

	return 0;
}
