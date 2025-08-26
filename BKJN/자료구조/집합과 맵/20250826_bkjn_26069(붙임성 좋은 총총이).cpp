#include <iostream>
#include <map>
using namespace std;

map <string, bool> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		
		if (str1 == "ChongChong") {
			m[str1] = true;
		}
		else if (str2 == "ChongChong") {
			m[str2] = true;
		}

		if (m[str1]) {
			m[str2] = true;
		}
		else if (m[str2]) {
			m[str1] = true;
		}
	}

	int res = 0;
	for (auto it : m) {
		if (it.second) {
			res++;
		}
	}

	cout << res << '\n';

	return 0;
}
