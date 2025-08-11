#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

vector <int> v[MAX];
int parent[MAX];
int level[MAX];
bool hasParent[MAX];

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
	int T;
	cin >> T;

	int N;
	for (int t = 1; t <= T; t++) {
		cin >> N;

		int A, B;
		for (int i = 0; i < (N - 1); i++) {
			cin >> A >> B;
			v[A].push_back(B);
			v[B].push_back(A);
			hasParent[B] = true;
		}

		int root = 1;
		for (int i = 1; i < N; i++) {
			if (!hasParent[i]) {
				root = i;
				break;
			}
		}

		setTree(root, 0);

		cin >> A >> B;

		cout << LCA(A, B) << '\n';

		for (int i = 1; i <= N; i++) {
			v[i].clear();
			parent[i] = 0;
			level[i] = 0;
			hasParent[i] = false;
		}
	}

	return 0;
}
