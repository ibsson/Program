#include <iostream>
#include <vector>
using namespace std;

int getIdx(vector <int>& LIS, int val) {
	int start = 0, end = LIS.size() - 1, mid = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		if (LIS[mid] > val) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector <int> v;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	vector <int> LIS;

	for (int i = 0; i < N; i++) {
		int idx = getIdx(LIS, v[i]);

		if (idx == LIS.size()) {
			LIS.push_back(v[i]);
		}
		else {
			LIS[idx] = v[i];
		}
	}

	cout << v.size() - LIS.size() << '\n';

	return 0;
}
