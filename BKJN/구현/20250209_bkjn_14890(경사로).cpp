#include <iostream>
#include <string.h>
using namespace std;

#define MAX 101

int N, L, result;
int map[MAX][MAX];
int visited[MAX];

bool checkRow(int idx) {
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < (N - 1); i++) {
		if (map[idx][i + 1] - map[idx][i] == 1) {
			for (int j = 0; j < L; j++) {
				if (i - j < 0) return false;
				if (visited[i - j]) return false;
				if (map[idx][i - j] != map[idx][i]) return false;

				visited[i - j] = true;
			}
		}
		else if (map[idx][i + 1] - map[idx][i] == -1) {
			for (int j = 1; j <= L; j++) {
				if (i + j > (N - 1)) return false;
				if (visited[i + j]) return false;
				if (map[idx][i + j] != map[idx][i + 1]) return false;

				visited[i + j] = true;
			}
		}
		else if(map[idx][i + 1] - map[idx][i] != 0) return false;
	}

	return true;
}

bool checkCol(int idx) {
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < (N - 1); i++) {
		if (map[i + 1][idx] - map[i][idx] == 1) {
			for (int j = 0; j < L; j++) {
				if (i - j < 0) return false;
				if (visited[i - j]) return false;
				if (map[i - j][idx] != map[i][idx]) return false;

				visited[i - j] = true;
			}
		}
		else if (map[i + 1][idx] - map[i][idx] == -1) {
			for (int j = 1; j <= L; j++) {
				if (i + j > (N - 1)) return false;
				if (visited[i + j]) return false;
				if (map[i + j][idx] != map[i + 1][idx]) return false;

				visited[i + j] = true;
			}
		}
		else if(map[i + 1][idx] - map[i][idx] != 0) return false;
	}

	return true;
}

int main() {

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		if (checkRow(i)) result++;
		if (checkCol(i)) result++;
	}

	cout << result << "\n";

	return 0;
}
