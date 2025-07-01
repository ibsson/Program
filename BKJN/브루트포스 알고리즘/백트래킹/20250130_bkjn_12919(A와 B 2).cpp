#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int chk = 0;

void backTracking(string S, string T) {
	if (S.length() == T.length()) {
		if (!S.compare(T)) {
			chk = 1;
			return;
		}
		else return;
	}

	if (T.front() == 'B') {
		if (T.back() == 'B') {
			string tmp;
			tmp += T;
			tmp.erase(tmp.begin(), tmp.begin() + 1);
			reverse(tmp.begin(), tmp.end());
			backTracking(S, tmp);
		}
		else if(T.back() == 'A') {
			string tmp_1;
			tmp_1 += T;
			tmp_1.erase(tmp_1.end() - 1, tmp_1.end());
			backTracking(S, tmp_1);

			string tmp_2;
			tmp_2 += T;
			tmp_2.erase(tmp_2.begin(), tmp_2.begin() + 1);
			reverse(tmp_2.begin(), tmp_2.end());
			backTracking(S, tmp_2);
		}
	}
	else {
		if (T.back() == 'A') {
			string tmp;
			tmp += T;
			tmp.erase(tmp.end() - 1, tmp.end());
			backTracking(S, tmp);
		}
	}
}

int main(void) {

	string S, T;

	cin >> S;
	cin >> T;

	backTracking(S, T);

	cout << chk << "\n";

	return 0;
}
