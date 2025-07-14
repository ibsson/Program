#include <iostream>
#include <map>
using namespace std;

int main() {
	string S;
	cin >> S;

	map <string, int> m;

	for (int i = 0; i < S.size(); i++) {
		string tmp = "";
		for (int j = i; j < S.size(); j++) {
			tmp += S[j];
			m[tmp]++;
		}
	}

	cout << m.size() << '\n';

	return 0;
}
