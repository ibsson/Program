#include <iostream>
using namespace std;

#define MAX_N 1000001

int len[MAX_N];

int main() {

	int N, M;
	cin >> N >> M;

	int _max = -1;
	for (int i = 0; i < N; i++) {
		cin >> len[i];
		if (_max < len[i]) _max = len[i];
	}

	long long int res = -1;
	long long int begin = 0, finish = _max;
	while (begin <= finish) {
		long long int pivot = (begin + finish) / 2;

		long long int cnt = 0;
		for (int i = 0; i < N; i++) {
			if(len[i] > pivot) cnt += (len[i] - pivot);
		}

		if (cnt < M) {
			finish = pivot - 1;
		}
		else if (cnt >= M) {
			res = pivot;
			begin = pivot + 1;
		}
	}

	cout << res << "\n";

	return 0;
}
