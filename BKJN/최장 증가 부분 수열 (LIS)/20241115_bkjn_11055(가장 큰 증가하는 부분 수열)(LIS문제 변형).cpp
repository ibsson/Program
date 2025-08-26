#include <iostream>
#include <vector>
#define MAX 1002
using namespace std;

vector <int> v;
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		v.push_back(tmp);
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = v[i];
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
		res = max(res, dp[i]);
	}

	cout << res << '\n';

	return 0;
}

/*
#include <iostream>
using namespace std;

int main(void) {

	int N = 0;
	int A[1001] = { 0 };
	int D[1001] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int max = -1;

	for (int i = 0; i < N; i++) {
		D[i] = A[i];
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i] && D[i] < A[i] + D[j]) D[i] = A[i] + D[j];
		}
		if (max < D[i]) max = D[i];
	}

	cout << max << endl;

	return 0;
}

/*
이 문제는 최장길이부분수열을 dp로 푸는 알고리즘(LIS)을 활용해서 풀었다.
현재 비교 기준값이 이전번째 까지의 합 + 자신의 값보다 작을때 D[i] = D[j] + A[i] 하는 방법으로 풀었다.
조금 어려웠지만 그래도 풀어내서 좋았다.
*/
*/
