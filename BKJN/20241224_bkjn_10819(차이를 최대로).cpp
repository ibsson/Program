#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(void) {

	deque <int> dq;
	int N = 0;
	int num[9] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num + N);

	int front = 0, back = (N - 1);
	int _front = front, _back = back;

	while (front <= back) {
		if (front == back) {
			if (abs(dq.front() - num[front]) > abs(dq.back() - num[front])) {
				dq.push_front(num[front]);
				break;
			}
			else {
				dq.push_back(num[front]);
				break;
			}
		}

		dq.push_front(num[_front]);
		dq.push_back(num[_back]);
		
		front++;
		back--;
		
		if (front % 2 == 0) {
			_front = back, _back = front;

			int tmp = _front;
			_front = _back;
			_back = tmp;
		}
		else {
			_front = front; _back = back;

			int tmp = _front;
			_front = _back;
			_back = tmp;
		}
	}

	int sum = 0;

	for (int i = 0; i < (dq.size() - 1); i++) {
		sum += abs(dq[i] - dq[i + 1]);
	}

	cout << sum << "\n";

	return 0;
}
