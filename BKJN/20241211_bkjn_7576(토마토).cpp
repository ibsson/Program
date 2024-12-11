#include <iostream>
#include <queue>
using namespace std;

int Box[1001][1001];
int Visited[1001][1001];
int Move[4][2] = { {-1, 0},{0, -1},{1, 0},{0, 1} };
int M, N;

void BFS();

int main(void) {

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Box[i][j];
		}
	}

	BFS();

	int Result = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Box[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}

			if (Result < Box[i][j]) Result = Box[i][j];
		}
	}

	cout << Result - 1 << "\n";

	return 0;
}

void BFS() {
	queue <pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Box[i][j] == 1) {
				q.push({ i, j });
				Visited[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int _y = q.front().first;
		int _x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_y = _y + Move[i][0];
			int n_x = _x + Move[i][1];
			
			if (n_y >= 0 && n_y < N && n_x >= 0 && n_x < M && Visited[n_y][n_x] == 0 && Box[n_y][n_x] == 0) {
				q.push({ n_y, n_x });
				Visited[n_y][n_x] = 1;
				Box[n_y][n_x] = Box[_y][_x] + 1;
			}
		}
	}
}

/*
BFS문제를 풀다 보니까 문제를 보면 DFS가 좋을지, BFS가 좋을지 감이 잡히기 시작한다.
좋은 신호라고 생각한다. 
그리고 queue를 좀 더 잘 활용할 수 있게 된 것 같다.
BFS문제를 푸는데 요령도 생겨서 재밌게 풀 수 있었던 것 같다.
앞으로도 계속 풀어봐야겠다.
*/
