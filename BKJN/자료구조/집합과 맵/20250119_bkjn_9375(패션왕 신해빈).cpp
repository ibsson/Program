#include <iostream>
#include <map>
#include <string>
using namespace std;

int T, n;
string kind;
string str;
map <string, int> m;

int main(void) {

	cin >> T;

	for (int i = 0; i < T; i++) {
		int result = 1;

		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> str >> kind;

			m[kind]++;
		}

		for (auto it = m.begin(); it != m.end(); it++) {
			result *= (it->second + 1);
		}

		cout << result - 1 << "\n";

		m.clear();
	}

	return 0;
}
