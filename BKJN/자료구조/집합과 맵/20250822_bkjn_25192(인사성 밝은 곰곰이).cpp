#include <iostream>
#include <map>
using namespace std;

map <string, int> m;

int main() {
  ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int N;
	cin >> N;

	int res = 0, tmp = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "ENTER") {
			m.clear();
			res += tmp;
			tmp = 0;
		}
		else {
			if (m[str] == 0) {
				tmp++;
			}
			m[str]++;
		}
	}
	res += tmp;

	cout << res << '\n';

	return 0;
}
