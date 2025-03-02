#include <iostream>
using namespace std;

#define MAX 202

int N, M;
int city[MAX][MAX];
int parent[MAX];
int plan[1001];

int findParent(int x) {
	if (parent[x] != x) return parent[x] = findParent(parent[x]);
	return x;
}

void merge(int x, int y) {
	int a = findParent(x);
	int b = findParent(y);

	if (a != b) {
		if (parent[a] > parent[b]) {
			parent[a] = b;
		}
		else {
			parent[b] = a;
		}
	}
}

void Input() {
	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> city[i][j];

			if (city[i][j] == 1) {
				merge(i, j);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> plan[i];
	}
}

void printResult() {
	int chk = parent[plan[0]];
	for (int i = 0; i < M; i++) {
		if (chk != parent[plan[i]]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

void solve() {
	Input();
	printResult();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
