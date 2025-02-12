#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack <char> s;

int getResult() {

	int result = 0, tmp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			tmp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				result = 0;
				break;
			}

			if (str[i - 1] == '(') {
				result += tmp;
				tmp /= 2;
				s.pop();
			}
			else {
				tmp /= 2;
				s.pop();
			}
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				result = 0;
				break;
			}

			if (str[i - 1] == '[') {
				result += tmp;
				tmp /= 3;
				s.pop();
			}
			else {
				tmp /= 3;
				s.pop();
			}
		}
	}

	if (!s.empty()) {
		result = 0;
	}

	return result;
}

int main() {

	cin >> str;

	cout << getResult() << "\n";

	return 0;
}
