#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, max_result;
string str;
map <string, int> m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		m[str]++;
	}

	string tmp;

	for (auto it = m.begin(); it != m.end(); it++) {

		if (max_result < it->second) {
			max_result = it->second;
			tmp = it->first;
		}
	}

	cout << tmp << "\n";

	return 0;
}
