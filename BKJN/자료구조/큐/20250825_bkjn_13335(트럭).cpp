#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue <int> t;
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w, L;
	cin >> n >> w >> L;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		t.push(tmp);
	}

	for (int i = 0; i < w; i++) {
		q.push(0);
	}

	int time = 0, cur = 0;
	while (!q.empty()) {
		time++;
		cur -= q.front();
		q.pop();

		if (!t.empty()) {
			if (cur + t.front() <= L) {
				cur += t.front();
				q.push(t.front());
				t.pop();
			}
			else {
				q.push(0);
			}
		}
	}

	cout << time << '\n';

	return 0;
}
