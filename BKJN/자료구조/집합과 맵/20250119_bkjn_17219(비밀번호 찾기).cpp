#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
string site, password;
map <string, string> m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> site >> password;

		m[site] = password;
	}

	for (int i = 0; i < M; i++) {
		cin >> site;

		auto it = m.find(site);

		cout << it->second << "\n";
	}

	return 0;
}
