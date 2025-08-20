#include <iostream>
#include <deque>
#include <stack>
using namespace std;

deque <int> dq;
stack <int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		dq.push_back(tmp);
	}

	int num = 1;
	bool chk = true;
	while (num <= N) {
		if (!dq.empty() && dq.front() == num) {
			dq.pop_front();
			num++;
		}
		else {
			if (!s.empty()) {
				if (s.top() == num) {
					s.pop();
					num++;
				}
				else {
					if (s.top() < dq.front()) {
						chk = false;
						break;
					}
					else {
						s.push(dq.front());
						dq.pop_front();
					}
				}
			}
			else {
				s.push(dq.front());
				dq.pop_front();
			}
		}
	}

	if (!chk) cout << "Sad\n";
	else cout << "Nice\n";

	return 0;
}
