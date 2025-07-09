#include <iostream>
using namespace std;

#define MAX 6

long long int matrix[MAX][MAX];
long long int res[MAX][MAX] = { 0 };

int main() {
	int N;
	long long int B;
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
			if (i == j) res[i][j] = 1;
		}
	}

	while (B > 0) {
		long long int tmp[MAX][MAX] = { 0 };

		if (B % 2 == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int l = 0; l < N; l++) {
						tmp[i][j] += (res[i][l] * matrix[l][j]) % 1000;
						tmp[i][j] %= 1000;
					}
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					res[i][j] = tmp[i][j];
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					tmp[i][j] = 0;
				}
			}

			B--;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int l = 0; l < N; l++) {
					tmp[i][j] += (matrix[i][l] * matrix[l][j]) % 1000;
					tmp[i][j] %= 1000;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = tmp[i][j];
			}
		}

		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << res[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
