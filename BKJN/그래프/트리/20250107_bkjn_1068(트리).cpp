#include <iostream>
#include <vector>
using namespace std;

#define MAX 51

int N, cnt, target;
vector <int> tree[MAX];

void countLeaves(int node) {

	if (tree[node].empty()) {
		cnt++;
		return;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		countLeaves(tree[node][i]);
	}
}

int main(void) {

	cin >> N;

	int root = -1;

	for (int i = 0; i < N; i++) {
		int parent = 0;

		cin >> parent;

		if (parent == -1) {
			root = i;
		}
		else {
			tree[parent].push_back(i);
		}
	}

	cin >> target;

	if (target == root) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			if (tree[i][j] == target) {
				tree[i].erase(tree[i].begin() + j);
				break;
			}
		}
	}

	countLeaves(root);

	cout << cnt << "\n";

	return 0;
}
