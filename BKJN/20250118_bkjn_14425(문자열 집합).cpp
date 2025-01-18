#include <iostream>
#include <map>
using namespace std;

int N, M;
string str;
map <string, int> S;

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;

		S[str] = i;
	}

	int cnt = 0;

	for (int i = 0; i < M; i++) {
		cin >> str;

		auto it = S.find(str);

		if (it != S.end()) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
