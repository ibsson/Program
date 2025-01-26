#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector <pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {

	cin >> n;

	if (n == 0) {
		cout << "0\n";
		return 0;
	}

	int p = 0, d = 0;

	for (int i = 0; i < n; i++) {
		cin >> p >> d;

		v.push_back({ p,d });
	}

	sort(v.begin(), v.end(), compare);

	priority_queue<int, vector<int> , greater<int>> pq;
	pq.push(v[0].first);
	
	for (int i = 1; i < v.size(); i++) {
		if (pq.size() >= v[i].second) {
			if (pq.top() < v[i].first) {
				pq.pop();
				pq.push(v[i].first);
			}
		}
		else {
			pq.push(v[i].first);
		}
	}

	int result = 0;

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	cout << result << "\n";

	return 0;
}
