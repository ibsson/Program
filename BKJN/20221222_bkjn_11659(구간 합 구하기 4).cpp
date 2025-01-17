#include <iostream>
using namespace std;

int N, M;
int num[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		num[i] += num[i - 1];
	}

	int a = 0, b = 0;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		cout << num[b] - num[a - 1] << "\n";
	}

	return 0;
}
