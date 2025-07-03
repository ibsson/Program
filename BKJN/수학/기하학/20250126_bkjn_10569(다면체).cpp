#include <iostream>
using namespace std;

int main() {

	int T = 0, V = 0, E = 0, ans = 0;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> V >> E;
		
		ans = 2 + E - V;

		cout << ans << "\n";
	}

	return 0;
}
