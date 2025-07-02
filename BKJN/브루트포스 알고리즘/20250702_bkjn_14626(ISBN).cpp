#include <iostream>
using namespace std;

int main() {

	string str;
	cin >> str;

	int res = 0, tmp = 0;
	for (int i = 0; i < 13; i++) {
		if (str[i] == '*') {
			if (i % 2 == 0) {
				tmp = 1;
			}
			else tmp = 3;

			continue;
		}

		int num = str[i] - '0';
		if (i % 2 == 0) {
			res += num * 1;
		}
		else res += num * 3;
	}

	for (int i = 0; i < 10; i++) {
		res += tmp * i;

		if (res % 10 == 0) {
			cout << i << "\n";
			break;
		}

		res -= tmp * i;
	}

	return 0;
}
