#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#define MAX 1002
using namespace std;

struct Node {
	int x, y;
};

struct Edge {
	double w;
	int from, to;
};

vector <Node> v;
vector <Edge> e;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 0; i < (N - 1); i++) {
		for (int j = (i + 1); j < N; j++) {
			double dist = sqrt(pow((v[i].x - v[j].x), 2) + pow((v[i].y - v[j].y), 2));

			e.push_back({ dist, (i + 1), (j + 1) });
		}
	}
	
	sort(e.begin(), e.end(), [](Edge a, Edge b) { return a.w < b.w; });

	for (auto i : e) {
		double w = i.w;
		int from = i.from, to = i.to;

		if (Find(from) == Find(to)) continue;
		Union(from, to);
		res += w;
	}

	cout << fixed << setprecision(2) << res << '\n';

	return 0;
}
