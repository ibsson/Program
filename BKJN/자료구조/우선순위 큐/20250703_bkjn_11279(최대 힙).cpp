#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue <int, vector<int>> PQ;

	int N;
	cin >> N;
	
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		
		if (num == 0) {
			if (PQ.empty()) cout << 0 << "\n";
			else {
				cout << PQ.top() << "\n";
				PQ.pop();
			}
		}
		else {
			PQ.push(num);
		}
	}

	return 0;
}
