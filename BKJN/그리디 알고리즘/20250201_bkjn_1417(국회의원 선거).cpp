#include <iostream>
#include <queue>
using namespace std;

int N, num;
priority_queue <int> pq;

int main() {

	cin >> N;
	cin >> num;

	if(N == 1) {
		cout << "0\n";
		return 0;
	}

	int x = 0;

	for (int i = 1; i < N; i++) {
		cin >> x;

		pq.push(x);
	}

	int cnt = 0;

	while (num <= pq.top()) {
		int tmp = pq.top();
		pq.pop();
		tmp--;
		num += 1;
		cnt++;
		pq.push(tmp);
	}

	cout << cnt << "\n";

	return 0;
}
