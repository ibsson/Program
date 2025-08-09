#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
	int num, idx;
};

int main() {
	int N;
	cin >> N;

	stack <Node> s;
	vector <int> res;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		while (!s.empty() && s.top().num < tmp) {
			s.pop();
		}

		if (s.empty()) res.push_back(0);
		else res.push_back(s.top().idx);

		s.push({tmp, i + 1});
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';

	return 0;
}
