#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 100001
using namespace std;

int num[MAX];
int tree[4 * MAX];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];
	int mid = (start + end) / 2;

	return tree[node] = min(init(start, mid, (node * 2)), init(mid + 1, end, (node * 2) + 1));
}

int getResult(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return INT_MAX;
	if (left <= start && end <= right) return tree[node];
	
	int mid = (start + end) / 2;

	return min(getResult(start, mid, (node * 2), left, right), getResult(mid + 1, end, (node * 2) + 1, left, right));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	init(0, (N - 1), 1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		cout << getResult(0, (N - 1), 1, (a - 1), (b - 1)) << '\n';
	}

	return 0;
}
