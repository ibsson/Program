#include <iostream>
using namespace std;

int N;
string a, b;

int main(void) {

	cin >> N;

	cin >> a;
	cin >> b;

	string tmp_1 = a;
	int cnt_1 = 0, chk_1 = 0;

	for (int i = 1; i < tmp_1.length(); i++) { //0번 스위치를 안눌렀을때.
		if (tmp_1[i - 1] != b[i - 1]) {
			if (i == tmp_1.length() - 1) {
				for (int j = i - 1; j <= i; j++) {
					tmp_1[j] == '0' ? tmp_1[j] = '1' : tmp_1[j] = '0';
				}
				cnt_1++;
			}
			else {
				for (int j = i - 1; j <= (i + 1); j++) {
					tmp_1[j] == '0' ? tmp_1[j] = '1' : tmp_1[j] = '0';
				}
				cnt_1++;
			}
		}
	}

	if (!tmp_1.compare(b)) chk_1 = 1;

	string tmp_2 = a;
	int cnt_2 = 1, chk_2 = 0;

	tmp_2[0] == '0' ? tmp_2[0] = '1' : tmp_2[0] = '0';
	tmp_2[1] == '0' ? tmp_2[1] = '1' : tmp_2[1] = '0';

	for (int i = 1; i < tmp_2.length(); i++) { //0번 스위치를 안눌렀을때.
		if (tmp_2[i - 1] != b[i - 1]) {
			if (i == tmp_2.length() - 1) {
				for (int j = i - 1; j <= i; j++) {
					tmp_2[j] == '0' ? tmp_2[j] = '1' : tmp_2[j] = '0';
				}
				cnt_2++;
			}
			else {
				for (int j = i - 1; j <= (i + 1); j++) {
					tmp_2[j] == '0' ? tmp_2[j] = '1' : tmp_2[j] = '0';
				}
				cnt_2++;
			}
		}
	}

	if (!tmp_2.compare(b)) chk_2 = 1;

	if (!chk_1 && !chk_2) {
		cout << "-1\n";
	}
	else if (chk_1 && !chk_2) {
		cout << cnt_1 << "\n";
	}
	else if (!chk_1 && chk_2) {
		cout << cnt_2 << "\n";
	}
	else {
		cout << min(cnt_1, cnt_2) << "\n";
	}

	return 0;
}
