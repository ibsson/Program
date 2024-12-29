#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {

	while (1){
		stack <char> l;
		string str;

		getline(cin, str);

		if (str[0] == '.') break;

		int len = str.length();

		int chk = 1;

		for (int i = 0; i < len; i++) {
			if (str[i] == '.' && !l.empty()) {
				chk = 0;
				break;
			}

			if (str[i] == '(' || str[i] == '[') {
				l.push(str[i]);
			}
			
			if (str[i] == ')' || str[i] == ']') {
				if (!l.empty()) {
					int left = l.top();
					l.pop();

					if (left == '(' && str[i] == ']' || left == '[' && str[i] == ')') {
						chk = 0;
						break;
					}
				}
				else {
					chk = 0;
					break;
				}
			}
		}

		if (chk) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}
