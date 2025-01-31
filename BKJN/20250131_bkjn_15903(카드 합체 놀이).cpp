#include <iostream>
#include <queue>
using namespace std;

int n, m;
priority_queue <long long int, vector <long long int> , greater<long long int>> a;

int main() {

	cin >> n >> m;

	int x = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;

		a.push(x);
	}

	for (int i = 0; i < m; i++) {
		long long int tmp_1 = a.top();
		a.pop();

		long long int tmp_2 = a.top();
		a.pop();

		a.push(tmp_1 + tmp_2);
		a.push(tmp_1 + tmp_2);
	}

	long long int sum = 0;

	while (!a.empty()) {
		sum += a.top();
		a.pop();
	}

	cout << sum << "\n";

	return 0;
}
