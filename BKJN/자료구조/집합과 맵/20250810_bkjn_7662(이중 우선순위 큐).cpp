#include <iostream>
#include <queue>
#include <map>
#define MAX 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		priority_queue <long long int> _max;
		priority_queue <long long int, vector<long long int>, greater<long long int>> _min;
		map <long long int, int> m;

		int k;
		cin >> k;

		char order;
		long long int num;
		for (int i = 0; i < k; i++) {
			cin >> order >> num;

			if (order == 'I') {
				_min.push(num);
				_max.push(num);
				m[num]++;
			}
			else if (order == 'D') {
				if (m.empty()) continue;

				if (num == 1) {
					while (!_max.empty() && m[_max.top()] == 0) _max.pop();

					if (!_max.empty()) {
						m[_max.top()]--;
						if (m[_max.top()] == 0) m.erase(_max.top());
						_max.pop();
					}
				}
				else if (num == -1) {
					while (!_min.empty() && m[_min.top()] == 0) _min.pop();

					if (!_min.empty()) {
						m[_min.top()]--;
						if (m[_min.top()] == 0) m.erase(_min.top());
						_min.pop();
					}
				}
			}
		}

		while (!_max.empty() && m[_max.top()] == 0) _max.pop();
		while (!_min.empty() && m[_min.top()] == 0) _min.pop();

		if (_max.empty() || _min.empty()) cout << "EMPTY\n";
		else cout << _max.top() << ' ' << _min.top() << '\n';
	}

	return 0;
}
