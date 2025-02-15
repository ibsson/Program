#include <iostream>
#include <climits>
using namespace std;

int N, result = INT_MIN;
string str;

int cal(int num1, int num2, int mark) {
	int tmp = 0;
	if (mark == '+') tmp = num1 + num2;
	else if (mark == '*') tmp = num1 * num2;
	else if (mark == '-') tmp = num1 - num2;

	return tmp;
}

void dfs(int idx, int cur) {
	if (idx > N - 1) {
		result = max(result, cur);
		return;
	}

	char mark = (idx == 0) ? '+' : str[idx - 1];

	if (idx + 2 < N) {
		int bracket = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, cal(cur, bracket, mark));
	}

	dfs(idx + 2, cal(cur, str[idx] - '0', mark));
}

int main() {

	cin >> N;
	cin >> str;

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
