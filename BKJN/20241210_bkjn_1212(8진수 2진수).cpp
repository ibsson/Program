#include <iostream>
using namespace std;

int main(void) {

	string s;
	string result;

	cin >> s;

	int len = s.length();

	for (int i = 0; i < len; i++) {
		switch (s[i]) {
		case '0':
			if (i == 0) {
				result += '0';
				break;
			}
			result += "000";
			break;
		case '1':
			if (i == 0) {
				result += '1';
				break;
			}
			result += "001";
			break;
		case '2':
			if (i == 0) {
				result += "10";
				break;
			}
			result += "010";
			break;
		case '3':
			if (i == 0) {
				result += "11";
				break;
			}
			result += "011";
			break;
		case '4':
			result += "100";
			break;
		case '5':
			result += "101";
			break;
		case '6':
			result += "110";
			break;
		case '7':
			result += "111";
			break;
		}
	}

	cout << result << "\n";

	return 0;
}
