#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

	sort(v.begin(), v.end());

	int res = 0;

	for (int i = 0; i < N; i++) {
		int left = 0, right = N - 1;
		while (left < right) {
			if (i == left || i == right) {
				if (i == left) left++;
				else if (i == right) right--;

				continue;
			}

			int sum = v[left] + v[right];

			if (v[i] < sum) right--;
			else if (v[i] > sum) left++;
			else if (v[i] == sum) {
				res++;
				break;
			}
		}
	}

	cout << res << '\n';

	return 0;
}
