#include <iostream>
using namespace std;

int result[10];

void calc(int n, int ten) {
	while (n > 0) {
		result[n % 10] += ten;
		n /= 10;
	}
}

void solve(int a, int b, int ten) {
	while (a % 10 != 0 && a <= b) {
		calc(a, ten);
		a++;
	}
	if (a > b) return;
	while (b % 10 != 9 && b >= a) {
		calc(b, ten);
		b--;
	}

	int cnt = ((b / 10) - (a / 10) + 1);

	for (int i = 0; i < 10; i++) {
		result[i] += cnt * ten;
	}
	
	solve(a / 10, b / 10, ten * 10);
}

int main() {

	int N = 0;
	cin >> N;

	solve(1, N, 1);
	for (int i = 0; i < 10; i++) {
		cout << result[i] << " ";
	}

	return 0;
}
