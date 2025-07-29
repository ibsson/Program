#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, C;
int res = INT_MIN;
vector<int> house;

bool isAble(int dist) {
	int last = house[0], cnt = 1;
	for (int i = 1; i < N; i++) {
		if (house[i] - last >= dist) {
			cnt++;
			last = house[i];
		}
	}

	return cnt >= C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		house.push_back(tmp);
	}

	sort(house.begin(), house.end());

	int start = 1, end = house[N - 1], mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;

		if (isAble(mid)) {
			res = max(res, mid);
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << res << '\n';
	
	return 0;
}
