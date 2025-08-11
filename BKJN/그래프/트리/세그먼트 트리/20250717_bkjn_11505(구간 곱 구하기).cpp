#include <iostream>
#define MAX 1000001
#define MOD 1000000007
using namespace std;

long long int num[MAX];
long long int tree[4 * MAX];

long long int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];
	int mid = (start + end) / 2;

	return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, (node * 2) + 1)) % MOD;
}

long long int mul(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return (tree[node] % MOD);

	int mid = (start + end) / 2;

	return (mul(start, mid, node * 2, left, right) * mul(mid + 1, end, (node * 2) + 1, left, right)) % MOD;
}

void update(int start, int end, int node, int idx, int val) {
	if (idx < start || idx > end) return;

	if (start == end) {
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, val);
	update(mid + 1, end, (node * 2) + 1, idx, val);
	tree[node] = (tree[node * 2] * tree[(node * 2) + 1]) % MOD;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	init(0, (N - 1), 1);

	long long int a, b, c;
	for (int i = 0; i < (M + K); i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			update(0, (N - 1), 1, (b - 1), c);
			num[b - 1] = c;
		}
		else if (a == 2) {
			cout << mul(0, (N - 1), 1, (b - 1), (c - 1)) << '\n';
		}
	}

	return 0;
}
