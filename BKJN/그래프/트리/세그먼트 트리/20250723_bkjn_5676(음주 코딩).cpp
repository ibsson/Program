#include <iostream>
#define MAX 100001
using namespace std;

struct Node {
	bool negative;
	bool zero;
	bool positive;
};

int arr[MAX];
Node tree[MAX * 4];

Node init(int start, int end, int node) {
	if (start == end) {
		tree[node] = { false, false, false };

		if (arr[start] < 0) tree[node].negative = true;
		else if (arr[start] == 0) tree[node].zero = true;
		else tree[node].positive = true;

		return tree[node];
	}

	int mid = (start + end) / 2;

	Node left = init(start, mid, (node * 2));
	Node right = init((mid + 1), end, ((node * 2) + 1));

	tree[node] = { false, false, false };

	if (left.zero || right.zero) tree[node].zero = true;
	else if ((left.negative && right.negative) || (left.positive && right.positive)) tree[node].positive = true;
	else if ((left.negative && right.positive) || (left.positive && right.negative)) tree[node].negative = true;
	
	return tree[node];
}

Node update(int start, int end, int node, int idx, int num) {
	if (idx < start || idx > end) return tree[node];
	
	tree[node] = { false, false, false };

	if (start == end) {
		arr[start] = num;
		
		if (arr[start] < 0) tree[node].negative = true;
		else if (arr[start] == 0) tree[node].zero = true;
		else tree[node].positive = true;

		return tree[node];
	}

	int mid = (start + end) / 2;
	Node left = update(start, mid, (node * 2), idx, num);
	Node right = update((mid + 1), end, ((node * 2) + 1), idx, num);

	if (left.zero || right.zero) tree[node].zero = true;
	else if ((left.negative && right.negative) || (left.positive && right.positive)) tree[node].positive = true;
	else if ((left.negative && right.positive) || (left.positive && right.negative)) tree[node].negative = true;

	return tree[node];
}

Node getResult(int start, int end, int node, int left, int right) {
	if (left > end || right < start) {
		Node temp = { false, false, false };
		temp.positive = true;
		return temp;
	}

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	Node Left = getResult(start, mid, (node * 2), left, right);
	Node Right = getResult((mid + 1), end, ((node * 2) + 1), left, right);

	Node tmp = { false, false, false };

	if (Left.zero || Right.zero) tmp.zero = true;
	else if ((Left.negative && Right.negative) || (Left.positive && Right.positive)) tmp.positive = true;
	else if ((Left.negative && Right.positive) || (Left.positive && Right.negative)) tmp.negative = true;

	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	
	while (cin >> N >> K) {
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		init(0, (N - 1), 1);
		
		char a;
		int b, c;
		string res = "";
		for (int i = 0; i < K; i++) {
			cin >> a >> b >> c;

			if (a == 'C') {
				update(0, (N - 1), 1, (b - 1), c);
			}
			else if (a == 'P') {
				Node tmp = getResult(0, (N - 1), 1, (b - 1), (c - 1));
				
				if (tmp.zero) res += "0";
				else if (tmp.positive) res += "+";
				else res += "-";
			}
		}
		cout << res << '\n';
	}

	return 0;
}
