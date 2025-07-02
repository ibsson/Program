#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> Q;

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			if (Q.empty()) cout << 0 << "\n";
			else {
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
		else {
			Q.push(a);
		}
	}

	return 0;
}
