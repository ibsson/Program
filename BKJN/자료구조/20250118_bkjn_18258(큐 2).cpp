#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	queue <int> q;

	string order;

	for (int i = 0; i < N; i++) {
		cin >> order;

		if (!order.compare("push")) {
			int x = 0;

			cin >> x;
			q.push(x);
		}
		else if (!order.compare("pop")) {
			if (q.size() != 0) {
				cout << q.front() << "\n";
				q.pop();
			}
			else cout << "-1\n";
		}
		else if (!order.compare("size")) {
			cout << q.size() << "\n";
		}
		else if (!order.compare("empty")) {
			cout << q.empty() << "\n";
		}
		else if (!order.compare("front")) {
			if (q.size() == 0) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (!order.compare("back")) {
			if (q.size() == 0) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}

	return 0;
}
