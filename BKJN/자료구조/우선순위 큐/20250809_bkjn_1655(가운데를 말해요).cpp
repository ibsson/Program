#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue <int> left;
	priority_queue <int, vector<int>, greater<int>> right;

	int left_size = 0, right_size = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if (left.empty() || left.top() >= tmp) left.push(tmp);
		else right.push(tmp);

		while (left.size() > right.size() + 1) {
			right.push(left.top());
			left.pop();
		}
		while (right.size() > left.size()) {
			left.push(right.top());
			right.pop();
		}

		cout << left.top() << '\n';
	}

	return 0;
}
