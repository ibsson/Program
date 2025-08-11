#include <iostream>
#define MAX 100001
using namespace std;

struct Node {
	int even;
	int odd;
};

int arr[MAX];
Node tree[4 * MAX];

Node init(int start, int end, int node) {
	if (start == end) {
		if (arr[start] % 2 == 0) tree[node].even++;
		else tree[node].odd++;

		return tree[node];
	}

	int mid = (start + end) / 2;

	Node left = init(start, mid, (node * 2));
	Node right = init((mid + 1), end, ((node * 2) + 1));

	tree[node].even = left.even + right.even;
	tree[node].odd = left.odd + right.odd;

	return tree[node];
}

Node update(int start, int end, int node, int idx, int num) {
	if (idx < start || idx > end) return tree[node];

	if (start == end) {
		if (arr[start] % 2 == 0) {
			tree[node].even = 1, tree[node].odd = 0;
		}
		else {
			tree[node].even = 0, tree[node].odd = 1;
		}

		return tree[node];
	}

	int mid = (start + end) / 2;

	Node left = update(start, mid, (node * 2), idx, num);
	Node right = update((mid + 1), end, ((node * 2) + 1), idx, num);

	tree[node].even = left.even + right.even;
	tree[node].odd = left.odd + right.odd;

	return tree[node];
}

int getEven(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node].even;

	int mid = (start + end) / 2;
	
	return getEven(start, mid, (node * 2), left, right) + getEven((mid + 1), end, ((node * 2) + 1), left, right);
}

int getOdd(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node].odd;

	int mid = (start + end) / 2;

	return getOdd(start, mid, (node * 2), left, right) + getOdd((mid + 1), end, ((node * 2) + 1), left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init(0, (N - 1), 1);

	int M;
	cin >> M;

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			arr[b - 1] = c;
			update(0, (N - 1), 1, (b - 1), c);
		}
		else if (a == 2) {
			cout << getEven(0, (N - 1), 1, (b - 1), (c - 1)) << '\n';
		}
		else if (a == 3) {
			cout << getOdd(0, (N - 1), 1, (b - 1), (c - 1)) << '\n';
		}
	}

	return 0;
}
