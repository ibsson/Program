#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	string str;
	int cnt;
};

map <string, int> m;
vector <Node> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		m[str]++;
	}

	for (auto it : m) {
		if (it.first.length() >= M) {
			v.push_back({ it.first, it.second });
		}
	}

	sort(v.begin(), v.end(), [](Node a, Node b) {
		if (a.cnt != b.cnt) return a.cnt > b.cnt;
		if (a.str.length() != b.str.length()) return a.str.length() > b.str.length();
		return a.str < b.str;
	});

	for (auto it : v) {
		cout << it.str << '\n';
	}

	return 0;
}
