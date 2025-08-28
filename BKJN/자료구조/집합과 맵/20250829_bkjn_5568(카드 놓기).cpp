#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector <int> v;
map <string, bool> m;
bool visited[11];

int n, k;
string str;

void solve(int cnt) {
	if (cnt >= k) {
		if (!m[str]) {
			m[str] = true;
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			string tmp = str;
			str += to_string(v[i]);
			solve(cnt + 1);
			str = tmp;
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	solve(0);

	cout << m.size() << '\n';

	return 0;
}
