#include <iostream>
using namespace std;

#define MAX_K 10001

int len[MAX_K];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K, N;
	cin >> K >> N;

	int _max = -1;
	for (int i = 0; i < K; i++) {
		cin >> len[i];

		if (_max < len[i]) _max = len[i];
	}

	long long int res = -1;
	long long int begin = 1, finish = _max;
	while (1) {
		int cnt = 0;
		long long int pivot = (begin + finish) / 2;

		for (int i = 0; i < K; i++) {
			cnt += (len[i] / pivot);
		}

		if (cnt < N) {
			finish = pivot - 1;
		}
		else if (cnt >= N) {
			if (pivot > res) res = pivot;

			begin = pivot + 1;
		}

		if (begin > finish) break;
	}

	cout << res << "\n";

	return 0;
}
