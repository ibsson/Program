#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};

int main() {
	int N;
	cin >> N;

	priority_queue <int, vector<int>, compare> PQ;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (PQ.empty()) cout << 0 << '\n';
			else {
				cout << PQ.top() << '\n';
				PQ.pop();
			}
		}
		else {
			PQ.push(x);
		}
	}

	return 0;
}
