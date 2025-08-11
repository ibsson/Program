#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 100001
using namespace std;

struct Node {
	int _min;
	int _max;
};

int num[MAX];
Node tree[4 * MAX];

Node init(int start, int end, int node) {
	if (start == end) {
		tree[node]._min = num[start];
		tree[node]._max = num[start];
		return tree[node];
	}

	int mid = (start + end) / 2;
	Node left = init(start, mid, node * 2);
	Node right = init(mid + 1, end, (node * 2) + 1);

	tree[node]._min = min(left._min, right._min);
	tree[node]._max = max(left._max, right._max);
	return tree[node];
}

Node getResult(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return { INT_MAX, INT_MIN };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	Node Left = getResult(start, mid, node * 2, left, right);
	Node Right = getResult(mid + 1, end, (node * 2) + 1, left, right);

	Node tmp;
	tmp._min = min(Left._min, Right._min);
	tmp._max = max(Left._max, Right._max);

	return tmp;
}

void solution(int a, int b, int N) {
	Node res = getResult(0, (N - 1), 1, (a - 1), (b - 1));

	cout << res._min << ' ' << res._max << '\n';
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

		solution(a, b, N);
	}

	return 0;
}
