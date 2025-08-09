#include <iostream>
#include <deque>
using namespace std;

struct Node {
	int num, idx;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	deque <Node> dq;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		dq.push_back({ tmp, i + 1 });
	}

	while (!dq.empty()) {
		int next = dq.front().num;
		cout << dq.front().idx << ' ';
		dq.pop_front();

		if (dq.empty()) break;
		
		if (next > 0) {
			int i = 0;
			while (i != (next - 1)) {
				dq.push_back(dq.front());
				dq.pop_front();
				i++;
			}
		}
		else {
			int i = 0;
			while (i != next) {
				dq.push_front(dq.back());
				dq.pop_back();
				i--;
			}
		}
	}

	return 0;
}
