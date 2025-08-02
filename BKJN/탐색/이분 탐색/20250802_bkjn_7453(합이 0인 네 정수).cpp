#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long int> A;
vector <long long int> B;
vector <long long int> C;
vector <long long int> D;
vector <long long int> v1;
vector <long long int> v2;

int getLower(int target) {
	int left = 0, right = v2.size() - 1, mid = 0;
	int idx = -1;
	while (left <= right) {
		mid = (left + right) / 2;

		if (target == v2[mid]) {
			idx = mid;
			right = mid - 1;
		}
		else if (target < v2[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return idx;
}

int getUpper(int target) {
	int left = 0, right = v2.size() - 1, mid = 0;
	int idx = -1;
	while (left <= right) {
		mid = (left + right) / 2;

		if (target == v2[mid]) {
			idx = mid;
			left = mid + 1;
		}
		else if (target < v2[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long int a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(A[i] + B[j]);
			v2.push_back(C[i] + D[j]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long int res = 0;

	for (int i = 0; i < v1.size(); i++) {
		int lower = getLower(-v1[i]);
		if (lower == -1) continue;

		int upper = getUpper(-v1[i]);

		res += (upper - lower + 1);
	}

	cout << res << '\n';

	return 0;
}
