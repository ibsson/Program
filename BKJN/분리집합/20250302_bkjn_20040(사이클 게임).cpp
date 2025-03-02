#include <iostream>
#include <vector>
using namespace std;

#define MAX 500001

int n, m;
vector <pair<int, int>> v;
int parent[MAX];

void Input() {
	cin >> n >> m;

	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}

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
		else parent[y] = x;
	}
}

void playGame() {
	int result = 0;
	for (int i = 0; i < m; i++) {
		int a = findParent(v[i].first);
		int b = findParent(v[i].second);

		if (a == b) {
			result = i + 1;
			break;
		}

		merge(a, b);
	}

	cout << result << "\n";
}

void solve() {
	Input();
	playGame();
}

int main() {

	solve();

	return 0;
}
