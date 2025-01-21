#include <iostream>
#include <queue>
#include <string>
using namespace std;

string num1, num2;
int len;

int bfs(string n1, string n2) {
	queue <pair<string, int>> q;
	q.push({ n1, 0 });

	while (!q.empty()) {
		string str = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (!str.compare(n2)) return cnt;

		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				string tmp_str = str;
				tmp_str += '1';

				if (tmp_str.length() > len) continue;

				q.push({ tmp_str, cnt + 1 });
			}
			else if (i == 1) {
				long long int tmp = stoll(str);
				tmp *= 2;
				string tmp_str = to_string(tmp);

				if (tmp_str.length() > len) continue;

				q.push({ tmp_str, cnt + 1 });
			}
		}
	}

	return -2;
}

int main(void) {

	cin >> num1 >> num2;

	len = num2.length();

	cout << bfs(num1, num2) + 1 << "\n";

	return 0;
}
