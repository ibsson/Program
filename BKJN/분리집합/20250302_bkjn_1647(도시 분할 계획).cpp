#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

struct node {
	int a;
	int b;
	int w;
};

int N, M, temp, ans;
int parent[MAX];
vector <node> v;

bool compare(node a, node b) {
	return a.w < b.w;
}

void Input() {
	cin >> N >> M;

	int A = 0, B = 0, C = 0;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		node tmp = { A, B, C };
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 1; i <= N; i++) {
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
		else {
			parent[y] = x;
		}
	}
}

void deleteWay() {
	for (int i = 0; i < M; i++) {
		int x = findParent(v[i].a);
		int y = findParent(v[i].b);

		if (x == y) continue;

		merge(x, y);
		ans += v[i].w;
		temp = max(temp, v[i].w);
	}

	cout << ans - temp << "\n";
}

void solve() {
	Input();
	deleteWay();
}

int main() {

	solve();

	return 0;
}
