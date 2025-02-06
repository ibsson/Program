#include <iostream>
using namespace std;

#define MAX 21

int N, M, K, x, y, chk;
int map[MAX][MAX];
int order[1001];
int dice[6];
int tmp[6];

void getResult(int idx) {
	chk = 0;

	for (int i = 0; i < 6; i++) {
		tmp[i] = dice[i];
	}

	switch (order[idx]) {
	case 1:
		if (y + 1 == M) {
			chk = 1;
			return;
		}
		y++;

		swap(dice[1], dice[4]);
		swap(dice[3], dice[5]);
		swap(dice[4], dice[5]);

		if (map[x][y] == 0) {
			map[x][y] = dice[3];
		}
		else {
			dice[3] = map[x][y];
			map[x][y] = 0;
		}

		break;
	case 2:
		if (y - 1 == -1) {
			chk = 1;
			return;
		}
		y--;

		swap(dice[1], dice[5]);
		swap(dice[3], dice[5]);
		swap(dice[3], dice[4]);

		if (map[x][y] == 0) {
			map[x][y] = dice[3];
		}
		else {
			dice[3] = map[x][y];
			map[x][y] = 0;
		}

		break;
	case 3:
		if (x - 1 == -1) {
			chk = 1;
			return;
		}
		x--;

		swap(dice[0], dice[1]);
		swap(dice[1], dice[2]);
		swap(dice[2], dice[3]);

		if (map[x][y] == 0) {
			map[x][y] = dice[3];
		}
		else {
			dice[3] = map[x][y];
			map[x][y] = 0;
		}

		break;
	case 4:
		if (x + 1 == N) {
			chk = 1;
			return;
		}
		x++;

		swap(dice[0], dice[3]);
		swap(dice[1], dice[3]);
		swap(dice[2], dice[3]);

		if (map[x][y] == 0) {
			map[x][y] = dice[3];
		}
		else {
			dice[3] = map[x][y];
			map[x][y] = 0;
		}

		break;
	}
}

int main() {

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}

	for (int i = 0; i < K; i++) {
		getResult(i);
		if (!chk) {
			cout << dice[1] << "\n";
		}
	}

	return 0;
}
