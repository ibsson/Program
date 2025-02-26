#include <iostream>
#include <queue>
using namespace std;

int cnt;
queue <int> f, t;

void hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {
		f.push(from), t.push(to);
		cnt++;
	}
	else {
		hanoi(n - 1, from, to, tmp);
		f.push(from), t.push(to);
		cnt++;
		hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	int n = 0;

	cin >> n;

	hanoi(n, 1, 2, 3);

	cout << cnt << "\n";

	while (!f.empty()) {
		cout << f.front() << " " << t.front() << "\n";
		f.pop(), t.pop();
	}

	return 0;
}
