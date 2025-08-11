#include <iostream>
#define MAX 1000002
using namespace std;

long long int num[MAX];
long long int tree[4 * MAX];

long long int init(int start, int end, int node) {
	if (start == end) return tree[node] = num[start];
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, (node * 2) + 1);
}

long long int sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, (node * 2) + 1, left, right);
}

void update(int start, int end, int node, int idx, long long int dif) {
	if (idx < start || idx > end) return;

	tree[node] += dif;

	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, dif);
	update(mid + 1, end, (node * 2) + 1, idx, dif);
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	init(0, N - 1, 1);

	long long int a, b, c;
	for (int i = 0; i < (M + K); i++) {
		cin >> a >> b >> c;
		
		if (a == 1) {
			update(0, N - 1, 1, b - 1, c - num[b - 1]);
			num[b - 1] = c;
		}
		else if (a == 2) {
			cout << sum(0, N - 1, 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}
