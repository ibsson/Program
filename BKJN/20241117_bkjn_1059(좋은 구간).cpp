#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int L = 0, n = 0;
	int num[51] = { 0 };

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> num[i];
	}

	sort(num, num + L);

	cin >> n;

	int min = n;

	for (int i = 0; i < L; i++) {
		if (min > num[i]) min = num[i];
	}

	long long int cnt = 0;

	if (min == n) {
		for (int i = 1; i <= n; i++) {
			for (int j = n; j < num[0]; j++) {
				if (j == i) continue;
				cnt++;
			}
		}
		cout << cnt << endl;

		return 0;
	}

	for (int i = 0; i < (L - 1); i++) {
		if (num[i] < n && num[i + 1] > n) {
			for (int j = (num[i] + 1); j <= n; j++) {
				for (int k = n; k < num[i + 1]; k++) {
					if (k == j) continue;
					cnt++;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}

/*
예제까지 다 맞았지만 n이 S의 원소중 최솟값보다 작을 수 있다는 조건을 빼서 시간이 좀 걸렸다.
사소하지만 이런 조건 하나 빼먹는걸로 틀린다.
앞으로는 조건을 빼먹지 않도록 조심해야겠다.
*/
