#include <iostream>
#include <map>
#include <vector>
using namespace std;

map <int, int> m;
vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			m[tmp]++;
		}

		int M;
		cin >> M;

		for (int i = 0; i < M; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 0; i < M; i++) {
			if (m.find(v[i]) == m.end()) cout << 0 << '\n';
			else cout << 1 << '\n';
		}

		m.clear(), v.clear();
	}

	return 0;
}
