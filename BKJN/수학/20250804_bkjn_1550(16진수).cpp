#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int res = 0, ten = 1;
	for (int i = str.size() - 1; i >= 0; i--) {

		if (str[i] >= 'A' && str[i] <= 'F') {
			res += (str[i] - 55) * ten;
		}
		else {
			res += (str[i] - '0') * ten;
		}

		ten *= 16;
	}

	cout << res << '\n';

	return 0;
}
