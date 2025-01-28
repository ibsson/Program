#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {

	cin >> N;

	int x = 0;

	for (int i = 0; i < N; i++) {
		cin >> x;

		pq.push(x);
	}

	if (N == 1) {
		cout << "0\n";
		return 0;
	}

	int result = 0;

	while (1) {
		int a = pq.top();
		pq.pop();

		int b = pq.top();
		pq.pop();

		result += a + b;

		if (pq.empty()) break;

		pq.push({ a + b });
	}

	cout << result << "\n";

	return 0;
}
