#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int Find(int N, int M) {
	int start = 0, end = v[N - 1];
	int res = -1;
	int mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] <= mid) tmp += v[i];
			else tmp += mid;
		}

		if (tmp <= M) {
			res = max(res, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);

		sum += tmp;
	}

	cin >> M;

	sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	if (sum <= M) cout << v[N - 1] << '\n';
	else {
		cout << Find(N, M) << '\n';
	}

	return 0;
}
