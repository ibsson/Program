#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt_p, cnt_m;
int arr[51];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

		if (arr[i] > 0) cnt_p++;
		if (arr[i] <= 0) cnt_m++;
	}

	sort(arr, arr + N);

	vector <int> p;
	vector <int> m;

	for (int i = 0; i < cnt_m; i++) {
		m.push_back(arr[i]);
	}

	for (int i = (N - 1); i > (N - 1) - cnt_p; i--) {
		p.push_back(arr[i]);
	}

	int result = 0;

	for (int i = 0; i < cnt_m; i++) {
		if (i == cnt_m - 1) {
			result += m[i];
			break;
		}

		result += m[i] * m[i + 1];
		i++;
	}

	for (int i = 0; i < cnt_p; i++) {
		if (i == cnt_p - 1) {
			result += p[i];
			break;
		}

		if (p[i] == 1 || p[i + 1] == 1) {
			result += p[i];
		}
		else {
			result += p[i] * p[i + 1];
			i++;
		}
	}

	cout << result << "\n";

	return 0;
}
