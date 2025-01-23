#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 102

int N;
vector <pair<int, int>> v;
int dp[MAX];

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main(void) {

	cin >> N;

	int from = 0, to = 0;

	for (int i = 0; i < N; i++) {
		cin >> from >> to;

		v.push_back({ from, to });
	}

	sort(v.begin(), v.end(), compare);

	int result = 0;

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) dp[i] = max(dp[i], dp[j] + 1);
		}

		result = max(result, dp[i]);
	}

	cout << N - result << "\n";

	return 0;
}

/*
정렬 후 최장길이 부분수열로 풀리는 창의적인 문제였다.
전혀 생각치도 못한 창의적인 방향으로 풀려서 재밌었던 문제였다.
*/
