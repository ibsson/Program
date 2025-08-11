#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 100001
using namespace std;

struct Node {
	int data;
	int idx;
};

int arr[MAX];
Node tree[MAX * 4];

Node init(int start, int end, int node) {
	if (start == end) return tree[node] = { arr[start], start + 1 };

	int mid = (start + end) / 2;

	Node left = init(start, mid, (node * 2));
	Node right = init((mid + 1), end, ((node * 2) + 1));

	return tree[node] = (left.data <= right.data) ? left : right;
}

Node update(int start, int end, int node, int idx, int num) {
	if (idx < start || idx > end) return tree[node];

	if (start == end) {
		tree[node].data = num;
		return tree[node];
	}

	int mid = (start + end) / 2;

	Node left = update(start, mid, (node * 2), idx, num);
	Node right = update((mid + 1), end, ((node * 2) + 1), idx, num);

	return tree[node] = (left.data <= right.data) ? left : right;
}

Node getResult(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return { INT_MAX, INT_MAX };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	Node Left = getResult(start, mid, (node * 2), left, right);
	Node Right = getResult((mid + 1), end, ((node * 2) + 1), left, right);

	return (Left.data <= Right.data) ? Left : Right;
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
			update(0, (N - 1), 1, (b - 1), c);
		}
		else if (a == 2) {
			cout << getResult(0, (N - 1), 1, (b - 1), (c - 1)).idx << '\n';
		}
	}

	return 0;
}
