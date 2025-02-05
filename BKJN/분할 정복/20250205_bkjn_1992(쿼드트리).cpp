#include <iostream>
#include <vector>
using namespace std;

#define MAX 65

char screen[MAX][MAX];
string result;

bool isSame(int r, int c, int N) {
	int num = screen[r][c];
	for (int i = r; i < r + N; i++) {
		for (int j = c; j < c + N; j++) {
			if (num != screen[i][j]) return false;
		}
	}

	return true;
}

void div(int r, int c, int N) {
	if (isSame(r, c, N)) {
		if (screen[r][c] == '0') {
			result += '0';
		}
		else if (screen[r][c] == '1') {
			result += '1';
		}
	}
	else {
		result += '(';
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				div(r + (i * (N / 2)), c + (j * (N / 2)), N / 2);
			}
		}
		result += ')';
	}
}

int main() {

	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> screen[i];
	}

	div(0, 0, N);

	cout << result << "\n";

	return 0;
}
