#include <iostream>
#include <deque>
using namespace std;

deque <int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;

		switch(a) {
		case 1:
			int b;
			cin >> b;
			dq.push_front(b);
			break;
		case 2:
			int c;
			cin >> c;
			dq.push_back(c);
			break;
		case 3:
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			break;
		case 4:
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			break;
		case 5:
			cout << dq.size() << '\n';
			break;
		case 6:
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
			break;
		case 7:
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << '\n';
			}
			break;
		case 8:
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << '\n';
			}
			break;
		}
	}

	return 0;
}
