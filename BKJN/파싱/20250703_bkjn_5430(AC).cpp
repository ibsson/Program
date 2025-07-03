#include <iostream>
#include <deque>
using namespace std;

#define MAX 100001

int num_1[MAX];
int num_2[MAX];
deque <int> DQ;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, idx = 0;
		bool chk = true, error = false;
		string order, str;

		cin >> order;
		cin >> n;
		cin >> str;

		//파싱
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '[' || str[j] == ']' || str[j] == ',') continue;
			else {
				int k = j;
				while (str[k] != ',' && str[k] != ']') {
					k++;
				}
				int a = k;

				int tmp = 0, ten = 1;
				for (k = k - 1; k >= j; k--) {
					tmp += (str[k] - '0') * ten;
					ten *= 10;
				}

				DQ.push_back(tmp);
				idx++;

				j = a;
			}
		}

		for (int j = 0; j < order.length(); j++) {
			if (order[j] == 'R') {
				if (chk) chk = false;
				else chk = true;
			}

			if (order[j] == 'D') {
				if (DQ.empty()) {
					cout << "error\n";
					error = true;
					break;
				}

				if (chk) DQ.pop_front();
				else DQ.pop_back();
			}
		}

		if (!error) {
			cout << '[';
			if (!DQ.empty()) {
				if (chk) {
					while (1) {
						cout << DQ.front();
						DQ.pop_front();

						if (DQ.empty()) break;

						cout << ',';
					}
				}
				else {
					while (1) {
						cout << DQ.back();
						DQ.pop_back();

						if (DQ.empty()) break;

						cout << ',';
					}
				}
			}
			cout << "]\n";
		}

		while (!DQ.empty()) DQ.pop_back();
	}

	return 0;
}
