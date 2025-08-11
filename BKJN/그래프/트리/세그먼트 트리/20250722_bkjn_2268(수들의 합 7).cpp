#include <iostream>
#define MAX 1000001
using namespace std;

int arr[MAX];
long long int tree[MAX * 4];

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

	int N, M;
	cin >> N >> M;

	int a, b, c;
	for(int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		
		if (a == 0) {
			if (b > c) {
				int tmp = b;
				b = c;
				c = tmp;
			}

			cout << sum(0, (N - 1), 1, (b - 1), (c - 1)) << '\n';
		}
		else if (a == 1) {
			update(0, (N - 1), 1, (b - 1), (c - arr[b - 1]));
			arr[b - 1] = c;
		}
	}

	return 0;
}
