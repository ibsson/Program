#include <iostream>
#include <map>
using namespace std;

#define MAX 1001

int N[MAX];
int M[MAX];

int main() {
	map <int, long long int> nSum;
	map <int, long long int> mSum;

	int T;
	cin >> T;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> M[i];
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += N[j];
			nSum[sum]++;
		}
	}

	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++) {
			sum += M[j];
			mSum[sum]++;
		}
	}

	long long int cnt = 0;
	for (auto it = nSum.begin(); it != nSum.end(); it++) {
		int tmp = T - (it->first);

		if (mSum.find(tmp) != mSum.end()) {
			cnt += mSum.at(tmp) * (it->second);
		}
	}

	cout << cnt << '\n';

	return 0;
}
