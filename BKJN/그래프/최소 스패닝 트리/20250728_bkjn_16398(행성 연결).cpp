#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

struct Node {
	int w, from, to;
};

vector <Node> v;
int map[MAX][MAX];
bool visited[MAX][MAX];
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				v.push_back({ map[i][j], i, j });
				visited[i][j] = true, visited[j][i] = true;
			}
		}
	}

	sort(v.begin(), v.end(), [](Node a, Node b) { return a.w < b.w; });

	for (int i = 0; i < v.size(); i++) {
		int w = v[i].w, from = v[i].from, to = v[i].to;

		if (Find(from) == Find(to)) continue;

		Union(from, to);

		res += w;
	}

	cout << res << '\n';

	return 0;
}
