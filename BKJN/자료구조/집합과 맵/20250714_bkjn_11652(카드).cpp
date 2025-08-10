#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;

	map <long long int, int> m;

	long long int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		m[num]++;
	}

	int _max = -1;
	long long int res = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (_max < it->second) {
			_max = it->second;
			res = it->first;
		}
		else if (_max == it->second && res > it->first) {
			res = it->first;
		}
	}

	cout << res << '\n';

	return 0;
}
