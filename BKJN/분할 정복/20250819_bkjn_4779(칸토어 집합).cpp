#include <iostream>
#include <cmath>
using namespace std;

string str;

void solve(int len, int start) {
	if (len == 1) return;

	for (int i = (start + (len / 3)); i < (start + (len / 3) * 2); i++) {
		str[i] = ' ';
	}

	solve(len / 3, start);
	solve(len / 3, start + (len / 3));
	solve(len / 3, start + (len / 3) * 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a;
	while (cin >> a) {
		for (int i = 0; i < pow(3, a); i++) {
			str += '-';
		}

		solve(pow(3, a), 0);

		cout << str << '\n';

		str = "";
	}

	return 0;
}
