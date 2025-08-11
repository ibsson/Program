#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int res = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		stack <char> s;
		for (int i = 0; i < str.length(); i++) {
			if (s.empty()) {
				s.push(str[i]);
			}
			else {
				if (s.top() == str[i]) {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
		}

		if (s.empty()) {
			res++;
		}
	}

	cout << res << '\n';
	
	return 0;
}
