#include <iostream>
#include <map>
using namespace std;

int N, M;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map <int, int> m;

	cin >> N;

	int x = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;
		m[x]++;
	}

	cin >> M;

	int n = 0;

	for (int i = 0; i < M; i++) {
		cin >> n;

		auto it = m.find(n);

		if (it != m.end()) cout << it->second << " ";
		else cout << "0 ";
	}

	return 0;
}
