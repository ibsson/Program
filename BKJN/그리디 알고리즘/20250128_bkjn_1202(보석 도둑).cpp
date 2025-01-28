#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, M, V, C;
vector <pair<int, int>> v;
priority_queue <int, vector <int>, greater <int>> pq;
priority_queue <pair<int, int>> jewel;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> M >> V;

		v.push_back({ V, M });
	}

	sort(v.begin(), v.end(), compare);

	int x = 0;

	for (int i = 0; i < K; i++) {
		cin >> x;

		pq.push(x);
	}

	int idx = 0;
	long long int result = 0;

	while (!pq.empty()) {
		for (int i = idx; i < N; i++) {
			if (pq.top() >= v[i].second) {
				jewel.push(v[i]);
			}
			else {
				idx = i;
				break;
			}

			if (i == (N - 1)) {
				idx = N;
			}
		}

		if (!jewel.empty()) {
			result += jewel.top().first;
			jewel.pop();
		}
		pq.pop();
	}

	cout << result << "\n";

	return 0;
}
