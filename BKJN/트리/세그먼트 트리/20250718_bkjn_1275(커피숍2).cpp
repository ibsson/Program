#include <iostream>
#define MAX 100001
using namespace std;

long long int num[MAX];
long long int tree[4 * MAX];

long long int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];

	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, (node * 2)) + init((mid + 1), end, ((node * 2) + 1));
}

long long int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, (node * 2), left, right) + sum((mid + 1), end, ((node * 2) + 1), left, right);
}

void update(int start, int end, int node, int idx, long long int dif) {
	if (idx < start || idx > end) return;

	tree[node] += dif;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, (node * 2), idx, dif);
	update((mid + 1), end, ((node * 2) + 1), idx, dif);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, Q;
	cin >> N >> Q;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	init(0, (N - 1), 1);

    int x, y;
	long long int a, b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;

		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}

		cout << sum(0, (N - 1), 1, (x - 1), (y - 1)) << '\n';
		update(0, (N - 1), 1, (a - 1), b - num[a - 1]);
		num[a - 1] = b;
	}

	return 0;
}
