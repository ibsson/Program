#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	vector <long long int> v;
	long long int res[3] = { 0 };

	for (int i = 0; i < N; i++) {
		long long int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	long long int _min = LLONG_MAX;
	for (int i = 0; i < N; i++) {
		int left = i + 1, right = N - 1;

		while (left < right) {
			long long int sum = v[left] + v[right] + v[i];

			if (abs(sum) < _min) {
				_min = abs(sum);
				res[0] = v[i], res[1] = v[left], res[2] = v[right];
			}

			if (sum < 0) left++;
			else right--;
		}
	}

	cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';

	return 0;
}
