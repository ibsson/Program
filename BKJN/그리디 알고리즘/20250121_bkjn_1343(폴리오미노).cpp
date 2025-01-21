#include <iostream>
#include <string>
using namespace std;

string str;
string a = "AAAA";
string b = "BB";
string result;

int main(void) {

	cin >> str;

	int cnt = 0;

	for (int i = 0; i < str.length() + 1; i++) {
		if (str[i] == 'X') cnt++;
		else if (str[i] == '.' || i == str.length()) {
			if (cnt % 2 != 0) {
				cout << "-1\n";
				
				return 0;
			}
			else {
				int cnt_a = cnt / 4;
				cnt %= 4;

				for (int j = 0; j < cnt_a; j++) {
					result += a;
				}

				int cnt_b = cnt / 2;
				cnt %= 2;

				for (int j = 0; j < cnt_b; j++) {
					result += b;
				}

				if(str[i] == '.') result += '.';
			}
		}
	}

	cout << result << "\n";

	return 0;
}
