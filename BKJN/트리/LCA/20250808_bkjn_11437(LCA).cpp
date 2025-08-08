#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50001
using namespace std;

vector <int> v[MAX];
int parent[MAX], level[MAX];

int LCA(int a, int b) {
	if (level[a] < level[b]) swap(a, b);

	while (level[a] != level[b]) {
		a = parent[a];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void setTree(int node, int pnode) {
	parent[node] = pnode;
	level[node] = level[pnode] + 1;

	for (int i = 0; i < v[node].size(); i++) {
		int child = v[node][i];
		if (child == pnode) continue;

		setTree(child, node);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < (N - 1); i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int M;
	cin >> M;
	
	setTree(1, 0);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}
