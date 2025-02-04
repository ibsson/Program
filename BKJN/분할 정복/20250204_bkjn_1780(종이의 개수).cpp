#include <iostream>
using namespace std;

#define MAX 2188

int cnt_1, cnt0, cnt1;
int paper[MAX][MAX];

bool isSame(int r, int c, int N) {
	int num = paper[r][c];
	for (int i = r; i < r + N; i++) {
		for (int j = c; j < c + N; j++) {
			if (num != paper[i][j]) return false;
		}
	}

	return true;
}

void div(int r, int c, int N) {
	if (isSame(r, c, N)) {
		if (paper[r][c] == 0) {
			cnt0++;
		}
		else if (paper[r][c] == 1) {
			cnt1++;
		}
		else if (paper[r][c] == -1) {
			cnt_1++;
		}
	}
	else {
		int tmp = N / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				div(r + (i * tmp), c + (j * tmp), N / 3);
			}
		}
	}
}

int main() {

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	div(0, 0, N);

	cout << cnt_1 << "\n";
	cout << cnt0 << "\n";
	cout << cnt1 << "\n";

	return 0;
}
