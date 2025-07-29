#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector <int> v;
	int res[2] = { 0 };

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), [](int a, int b) {return a < b; });

	int _min = INT_MAX;
	int left = 0, right = (N - 1);
	while (left < right) {
		int sum = v[left] + v[right];
		
		if (abs(sum) < _min) {
			_min = abs(sum);
			res[0] = v[left], res[1] = v[right];
		}
		
		if (sum < 0) left++;
		else right--;
	}

	cout << res[0] << ' ' << res[1] << '\n';

	return 0;
}
