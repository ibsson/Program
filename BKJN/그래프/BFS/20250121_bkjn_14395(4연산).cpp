#include <iostream>
#include <queue>
#include <set>
using namespace std;

char mark[4] = { '*', '+', '-', '/' };
set <long long int> s;

long long int calculate(int idx, long long int n) {
	if (idx == 0) return (n * n);
	else if (idx == 1) return (n + n);
	else if (idx == 2) return (n - n);
	else if (idx == 3) return (n / n);
}

string bfs(int start, int finish) {
	queue <pair<int, string>> q;
	q.push({ start, "" });
	s.insert(start);
	
	while (!q.empty()) {
		long long int cur_n = q.front().first;
		string str = q.front().second;
		q.pop();

		if (cur_n == finish) return str;

		for (int i = 0; i < 4; i++) {
			
			long long int next_n = calculate(i, cur_n);

			if (next_n > finish || next_n == 0) continue;
			if (s.find(next_n) != s.end()) continue;

			q.push({ next_n, (str + mark[i]) });
			s.insert(next_n);
		}
	}

	return "no";
}

int main(void) {

	int from = 0, to = 0;

	cin >> from >> to;

	if (from == to) {
		cout << "0\n";
		return 0;
	}

	string result = bfs(from, to);

	if (result == "no") cout << "-1\n";
	else cout << result << "\n";

	return 0;
}
