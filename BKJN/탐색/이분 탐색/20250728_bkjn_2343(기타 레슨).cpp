#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int _max = -1, sum = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);

		_max = max(_max, tmp);
		sum += tmp;
	}

	int res = 10000000;
	int start = _max, end = sum, mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;

		int cnt = 1, tmp_sum = 0;
		for (int i = 0; i < N; i++) {
			if (tmp_sum + v[i] > mid) {
				cnt++, tmp_sum = v[i];
				continue;
			}

			tmp_sum += v[i];
		}

		if (cnt > M) {
			start = mid + 1;
		}
		else if (cnt <= M) {
			res = min(res, mid);
			end = mid - 1;
		}
	}

	cout << res << '\n';

	return 0;
}
