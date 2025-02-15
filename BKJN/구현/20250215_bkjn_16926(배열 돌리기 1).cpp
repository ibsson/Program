#include <iostream>
using namespace std;

#define MAX 301

int N, M, R;
int arr[MAX][MAX];

void turnArr(int start_r, int finish_r, int start_c, int finish_c) {

	int from = arr[start_r][start_c], to = 0;
	for (int i = start_r + 1; i <= finish_r; i++) {
		to = arr[i][start_c];
		arr[i][start_c] = from;
		from = to;
	}

	for (int i = start_c + 1; i <= finish_c; i++) {
		to = arr[finish_r][i];
		arr[finish_r][i] = from;
		from = to;
	}

	for (int i = finish_r - 1; i >= start_r; i--) {
		to = arr[i][finish_c];
		arr[i][finish_c] = from;
		from = to;
	}

	for (int i = finish_c - 1; i >= start_c; i--) {
		to = arr[start_r][i];
		arr[start_r][i] = from;
		from = to;
	}
}

int main() {

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		int start_r = 0, finish_r = N - 1, start_c = 0, finish_c = M - 1;
		while (start_r < finish_r && start_c < finish_c) {
			turnArr(start_r, finish_r, start_c, finish_c);
			start_r++, finish_r--, start_c++, finish_c--;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
