#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	cin.ignore();

	for (int t = 1; t <= T; t++) {
		string str;
		stack <char> s;
		getline(cin, str);

		for (int i = 0; i <= str.length(); i++) {
			if (str[i] == ' ' || i == str.length()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
				continue;
			}

			s.push(str[i]);
		}

		cout << '\n';
	}

	return 0;
}
