#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

int N, max_dp, idx;
int arr[MAX];
int dp[MAX];
vector <int> v[MAX];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
	}

	v[0].push_back(arr[0]);

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					v[i].clear();
					
					for (int k = 0; k < v[j].size(); k++) {
						v[i].push_back(v[j][k]);
					}
				}
			}
		}
		v[i].push_back(arr[i]);

		if (max_dp < dp[i]) {
			max_dp = dp[i];
			idx = i;
		}
	}

	cout << dp[idx] << "\n";
	for (int i = 0; i < v[idx].size(); i++) {
		cout << v[idx][i] << " ";
	}
	cout << "\n";

	return 0;
}
