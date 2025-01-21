#include <iostream>
using namespace std;

#define MAX 51

int N, M;
string matrix_1[MAX];
string matrix_2[MAX];
string matrix_3[MAX];

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> matrix_1[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> matrix_2[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix_1[i][j] != matrix_2[i][j]) matrix_3[i] += '1';
			else matrix_3[i] += '0';
		}
	}

	int cnt = 0;

	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 2); j++) {
			if (matrix_3[i][j] == '1') {
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						if (matrix_3[k][l] == '1') matrix_3[k][l] = '0';
						else matrix_3[k][l] = '1';
					}
				}

				cnt++;
			}
		}
	}

	int chk = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix_3[i][j] == '1') {
				chk = 1;
				break;
			}
		}
	}

	if(!chk) cout << cnt << "\n";
	else cout << "-1\n";

	return 0;
}
