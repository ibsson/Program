#include <iostream>
#define MAX 1000001
using namespace std;

long long int tree[MAX * 4];

void update(int start, int end, int node, int idx, int price) {
	if (idx < start || idx > end) return;

	tree[node] += price;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, (node * 2), idx, price);
	update((mid + 1), end, ((node * 2) + 1), idx, price);
}

long long int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right)return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, (node * 2), left, right) + sum((mid + 1), end, ((node * 2) + 1), left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;

	int a, b, c;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			update(0, (N - 1), 1, (b - 1), c);
		}
		else if (a == 2) {
			cout << sum(0, (N - 1), 1, (b - 1), (c - 1)) << '\n';
		}
	}

	return 0;
}
