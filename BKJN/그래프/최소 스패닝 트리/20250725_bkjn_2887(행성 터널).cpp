#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX 100001
using namespace std;

struct Planet {
	int idx, x, y, z;
};

struct Edge {
	int w, from, to;
};

vector <Planet> v; 
vector <Edge> e;
int parent[MAX];
long long int res = 0;

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

	int N;
	cin >> N;

	int x, y, z;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		v.push_back({i, x, y, z});

		parent[i] = i;
	}

	sort(v.begin(), v.end(), [](Planet a, Planet b) { return a.x < b.x; });
	for (int i = 0; i < (N - 1); i++) {
		e.push_back({ abs(v[i].x - v[i + 1].x), v[i].idx, v[i + 1].idx });
	}

	sort(v.begin(), v.end(), [](Planet a, Planet b) { return a.y < b.y; });
	for (int i = 0; i < (N - 1); i++) {
		e.push_back({ abs(v[i].y - v[i + 1].y), v[i].idx, v[i + 1].idx });
	}

	sort(v.begin(), v.end(), [](Planet a, Planet b) { return a.z < b.z; });
	for (int i = 0; i < (N - 1); i++) {
		e.push_back({ abs(v[i].z - v[i + 1].z), v[i].idx, v[i + 1].idx });
	}
	
	sort(e.begin(), e.end(), [](Edge a, Edge b) { return a.w < b.w; });

	for (auto i : e) {
		long long int w = i.w;
		int from = i.from, to = i.to;

		if (Find(from) == Find(to)) continue;

		Union(from, to);

		res += w;
	}

	cout << res << '\n';

	return 0;
}
