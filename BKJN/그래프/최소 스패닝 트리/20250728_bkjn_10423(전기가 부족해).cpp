#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Node {
	int w, u, v;
};

int parent[MAX];
vector <int> power;
vector <Node> city;
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

	int N, M, K;
	cin >> N >> M >> K;
	
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		power.push_back(tmp);
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i < K; i++) {
		Union(power[0], power[i]);
	}

	int u, v, w;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;

		city.push_back({ w, u, v });
	}

	sort(city.begin(), city.end(), [](Node a, Node b) { return a.w < b.w; });

	for (int i = 0; i < M; i++) {
		int w = city[i].w, from = city[i].u, to = city[i].v;

		if (Find(from) == Find(to)) continue;

		Union(from, to);

		res += w;
	}

	cout << res << '\n';

	return 0;
}
