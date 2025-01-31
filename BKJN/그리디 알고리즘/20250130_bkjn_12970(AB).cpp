#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int a = 1; a < N; a++) {
		int b = N - a;

		if (a * b < K) {
			continue;
		}

		vector<int> pos_A(b + 1);

		for (int i = 0; i < a; i++) {
			int after = min(b, K);

			pos_A[b - after]++;
			K -= after;
		}

		for (int i = 0; i <= b; i++) {
			for (int j = 0; j < pos_A[i]; j++) {
				cout << 'A';
			}
			if (i < b) {
				cout << 'B';
			}
		}
		return 0;
	}

	cout << -1;

	return 0;
}
