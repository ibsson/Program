#include <iostream>
using namespace std;

#define MAX 1000001

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
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0, m = 0;

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	bool order;
	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		cin >> order >> a >> b;
		if (!order) {
			merge(a, b);
		}
		else if (order) {
			if (findParent(a) == findParent(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
