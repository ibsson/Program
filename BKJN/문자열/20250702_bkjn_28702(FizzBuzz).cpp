#include <iostream>
#include <string>
using namespace std;

int main() {

	string str[3];

	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}

	int tmp = 0, ten = 1;
	bool chk = false;
	for (int i = 0; i < 3; i++) {
		if (str[i][0] >= '0' && str[i][0] <= '9') {
			if (!chk) {
				chk = true;
				for (int j = str[i].length() - 1; j >= 0; j--) {
					tmp += ((str[i][j] - '0') * ten);
					ten *= 10;
				}
			}
		}
		if (chk) {
			tmp++;
		}
	}

	if (tmp % 3 == 0) {
		if (tmp % 5 == 0) cout << "FizzBuzz\n";
		else cout << "Fizz\n";
	}
	else if (tmp % 5 == 0) {
		cout << "Buzz\n";
	}
	else cout << tmp << "\n";

	return 0;
}
