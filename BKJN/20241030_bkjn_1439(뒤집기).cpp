#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string S;
	int cnt = 0;
	
	getline(cin, S);

	for (int i = 0; i < S.length() - 1; i++) {
		if (S[i] != S[i + 1]) {
			cnt++;
		}
	}

	if (cnt % 2 == 0) cout << cnt / 2 << endl;
	else cout << (cnt / 2) + 1 << endl;

	return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string S;
	int cnt_zero = 0, check = 0;

	getline(cin, S);

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '1' && check == 0) {
			cnt_zero++;
			check = 1;
		}
		if (S[i] == '0') check = 0;
	}

	int cnt_one = 0;
	check = 0;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '0' && check == 0) {
			cnt_one++;
			check = 1;
		}
		if (S[i] == '1') check = 0;
	}

	if (cnt_zero < cnt_one) printf("%d\n", cnt_zero);
	else printf("%d\n", cnt_one);

	return 0;
}
*/
