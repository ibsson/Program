#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		string str;
		cin >> str;
		
		stack <char> res;
		stack <char> tmp;
		for (int i = 0; i < str.length(); i++) {
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
				res.push(str[i]);
			}
			else if (str[i] == '<') {
				if (!res.empty()) {
					tmp.push(res.top());
					res.pop();
				}
			}
			else if (str[i] == '>') {
				if (!tmp.empty()) {
					res.push(tmp.top());
					tmp.pop();
				}
			}
			else if (str[i] == '-') {
				if (!res.empty()) {
					res.pop();
				}
			}
		}

		while (!res.empty()) {
			tmp.push(res.top());
			res.pop();
		}

		while (!tmp.empty()) {
			cout << tmp.top();
			tmp.pop();
		}
		cout << '\n';
	}

	return 0;
}
