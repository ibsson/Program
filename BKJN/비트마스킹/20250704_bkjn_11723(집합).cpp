#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M;
	cin >> M;

	int S = 0;

	string order;
	int x;
	for (int i = 0; i < M; i++) {
		cin >> order;

		if (order == "add") {
			cin >> x;
			int tmp = 1 << (x - 1);
			S |= tmp;
		}
		else if (order == "remove") {
			cin >> x;
			int tmp = 1 << (x - 1);
			S &= ~tmp;
		}
		else if (order == "check") {
			cin >> x;
			int tmp = 1 << (x - 1);
			if (S & tmp) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (order == "toggle") {
			cin >> x;
			int tmp = 1 << (x - 1);
			S ^= tmp;
		}
		else if (order == "all") {
			S = (1 << 20) - 1;
		}
		else if (order == "empty") {
			S = 0;
		}
	}
	
	return 0;
}
