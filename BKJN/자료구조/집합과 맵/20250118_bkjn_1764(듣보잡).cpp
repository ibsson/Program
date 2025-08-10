#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, cnt;
string str;
vector <string> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map <string, int> m;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;

		m[str]++;
	}

	for (int i = 0; i < M; i++) {
		cin >> str;

		auto it = m.find(str);

		if (it != m.end()) {
			cnt++;
			v.push_back(str);
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}
