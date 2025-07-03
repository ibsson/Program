#include <iostream>
using namespace std;

int main(void) {

	int N = 0, K = 0;

	cin >> N >> K;

	int tmp = 0, cnt = 0;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) cnt++;

		if (cnt == K) {
			cout << i << "\n";
			break;
		}

		if (i == N) cout << "0\n";
	}

	return 0;
}
