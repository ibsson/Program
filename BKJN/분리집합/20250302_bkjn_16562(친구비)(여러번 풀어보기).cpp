//복습

#include <iostream>
using namespace std;

#define MAX 10001

int N, M, k, ans;
int pay[MAX];
int parent[MAX];

int findParent(int x) {
	if (parent[x] != x) return parent[x] = findParent(parent[x]);
	return x;
}

void merge(int x, int y) {
	int a = findParent(x);
	int b = findParent(y);

	if (a != b) {
		if (pay[a] > pay[b]) {
			parent[a] = b;
		}
		else {
			parent[b] = a;
		}
	}
}

int main() {

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) {
		cin >> pay[i];
		parent[i] = i;
	}

	int from = 0, to = 0;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		merge(from, to);
	}

	for (int i = 1; i <= N; i++) {
		int x = findParent(i);
		int y = findParent(0);

		if (x != y) {
			ans += pay[x];
			merge(0, i);
		}
	}

	if (k >= ans) {
		cout << ans << "\n";
	}
	else {
		cout << "Oh no\n";
	}

	return 0;
}

/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX 10001

int N, M, k, ans;
int pay[MAX];
int parent[MAX];

int findParent(int x) {
	if (parent[x] != x) {
		return parent[x] = findParent(parent[x]);
	}
	return x;
}

void merge(int a, int b) {
	int x = findParent(a);
	int y = findParent(b);

	if (x != y) {
		if (pay[x] < pay[y]) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}
}

int main() {

	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++) {
		cin >> pay[i];
		parent[i] = i;
	}


	int from = 0, to = 0;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;

		merge(from, to);
	}

	for (int i = 1; i <= N; i++) {
		int root = findParent(i);
		if (root != findParent(0)) {
			ans += pay[root];
			merge(0, i);
		}
	}
	
	if (k >= ans) {
		cout << ans << "\n";
	}
	else {
		cout << "Oh no\n";
	}

	return 0;
}
*/
