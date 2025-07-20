#include <iostream>
#include <climits>
using namespace std;

int main() {
	int _min = INT_MAX;
	int sum = 0;
	bool chk = false;
	for (int i = 0; i < 7; i++) {
		int tmp;
		cin >> tmp;

		if (tmp % 2 != 0) {
			sum += tmp;
			_min = min(_min, tmp);
			chk = true;
		}
	}

	if (!chk) cout << "-1\n";
	else {
		cout << sum << '\n';
		cout << _min << '\n';
	}

	return 0;
}
