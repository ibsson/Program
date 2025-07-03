#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int Move[6][3] = { {0, 0, -1}, {0, 1, 0}, {0, 0, 1}, {0, -1, 0}, {-1, 0, 0}, {1, 0, 0} }; //x, z, y 순서

int M, N, H; //y, x, z 순서
int Box[101][101][101]; //x, z, y 순서
int Visited[101][101][101];

void BFS();

int main(void) {

	cin >> M >> N >> H;

	for (int i = (H - 1); i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> Box[j][i][k];
			}
		}
	}

	BFS();

	int Result = -1;

	for (int i = (H - 1); i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (Box[j][i][k] == 0) {
					cout << "-1\n";
					return 0;
				}

				if (Result < Box[j][i][k]) Result = Box[j][i][k];
			}
		}
	}

	cout << Result - 1 << "\n";

	return 0;
}

void BFS() {

	queue <tuple<int, int, int>> q;

	for (int i = (H - 1); i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (Box[j][i][k] == 1) {
					q.push(make_tuple(j, i, k));
					Visited[j][i][k] = 1;
				}
			}
		}
	}

	while (!q.empty()) {
		int _x = get<0>(q.front());
		int _z = get<1>(q.front());
		int _y = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int n_x = _x + Move[i][0];
			int n_z = _z + Move[i][1];
			int n_y = _y + Move[i][2];

			if (n_x >= 0 && n_x < N && n_z >= 0 && n_z < H && n_y >= 0 && n_y < M && Visited[n_x][n_z][n_y] == 0 && Box[n_x][n_z][n_y] == 0) {
				q.push(make_tuple(n_x, n_z, n_y));
				Visited[n_x][n_z][n_y] = 1;
				Box[n_x][n_z][n_y] = Box[_x][_z][_y] + 1;
			}
		}
	}
}

/*
3차원 배열의 가로 세로 높이 순서때문에 조금 힘들었던 문제다.
처음에 입력받을때 바닥부터 채워야 하는데 채우는 순서가 잘못됐어서 고치는데 시간이 오래 걸렸다.
앞으로 3차원 배열을 사용할때는 문제에서 주어지는 조건들과 잘 비교해서 순서를 잘 지켜야겠다.
배열에서는 첫번째가 세로, 두번째가 높이, 세번째가 가로 순서다.
*/
