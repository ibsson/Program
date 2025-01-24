#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

int main(void) {

	cin >> S;
	cin >> T;

	int len = T.length();

	for (int i = 0; i < len; i++) {
		if (T.length() == S.length()) {
			if (!T.compare(S)) {
				cout << "1\n";
				break;
			}
			else {
				cout << "0\n";
				break;
			}
		}

		if (T.back() == 'A') {
			T.pop_back();
		}
		else if (T.back() == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
	}

	return 0;
}
