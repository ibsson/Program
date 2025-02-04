#include <iostream>
using namespace std;

#define MAX 129

int cnt_0, cnt_1;
int paper[MAX][MAX];

bool isSame(int r, int c, int N) {
	int num = paper[r][c];

	for (int i = r; i < (r + N); i++) {
		for (int j = c; j < (c + N); j++) {
			if (num != paper[i][j]) return false;
		}
	}

	return true;
}

void div(int r, int c, int N) {
	if (isSame(r, c, N)) {
		if (paper[r][c] == 0) cnt_0++;
		else if (paper[r][c] == 1) cnt_1++;
	}
	else {
		int tmp = N / 2;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				div(r + (i * tmp), c + (j * tmp), tmp);
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

	cout << cnt_0 << "\n";
	cout << cnt_1 << "\n";

	return 0;
}
