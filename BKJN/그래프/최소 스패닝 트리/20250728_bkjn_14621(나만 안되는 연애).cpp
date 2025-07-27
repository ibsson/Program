#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1002
using namespace std;

struct Node {
	int w, from, to;
};

char arr[MAX];
int parent[MAX];
vector <Node> v;
vector <Node> selected;
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

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i + 1] = i + 1;
	}

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		v.push_back({ c, a, b });
	}

	sort(v.begin(), v.end(), [](Node a, Node b) {return a.w < b.w; });

	for (int i = 0; i < M; i++) {
		int w = v[i].w, from = v[i].from, to = v[i].to;

		if (arr[from] == arr[to]) continue;
		if (Find(from) == Find(to)) continue;

		Union(from, to);
		selected.push_back(v[i]);

		res += w;
	}

	if (selected.size() != (N - 1)) cout << -1 << '\n';
	else cout << res << '\n';

	return 0;
}
