#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	string bomb;
	cin >> bomb;

	string res;
	int len = bomb.size();
	for (int i = 0; i < str.size(); i++) {
		res += str[i];

		if ((res.size() >= len) && (res.substr(res.size() - len, len) == bomb)) res.erase(res.size() - len, len);
	}

	if (res == "") cout << "FRULA\n";
	else cout << res << '\n';

	return 0;
}
