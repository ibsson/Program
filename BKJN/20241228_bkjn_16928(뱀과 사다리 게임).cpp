#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 16

int ladder[MAX][2];
int snake[MAX][2];
int Visited[101];
int N, M, idx;

void BFS(int X){
	queue <int> q;

	q.push(X);
	Visited[X] = 0;

	while (!q.empty()) {
		int _x = q.front();
		q.pop();

		if (_x == 100) break;

		for (int i = 1; i <= 6; i++) {
			int n_x = _x + i;

			if (n_x > 100) continue;

			if (Visited[n_x] != -1) continue;

			for (int j = 0; j < N; j++) {
				if (n_x == ladder[j][0]) {
					n_x = ladder[j][1];
					break;
				}
			}

			for (int j = 0; j < M; j++) {
				if (n_x == snake[j][0]) {
					n_x = snake[j][1];
					break;
				}
			}

			if (Visited[n_x] == -1) { //방문하지 않은 점으로 뱀이나 사다리로 이동을 해도 그 값이 그 이동한 칸으로 도달하기 위한 최소경로이기 때문에 한번 더 밟았을때의 경우가 그 전 값보다 더 작지 않다.
				Visited[n_x] = Visited[_x] + 1;
				q.push(n_x);
			}
		}
	}
}

int main(void) {

	cin >> N >> M; 

	for (int i = 0; i < N; i++) {
		cin >> ladder[i][0] >> ladder[i][1];
	}

	for (int i = 0; i < M; i++) {
		cin >> snake[i][0] >> snake[i][1];
	}

	memset(Visited, -1, sizeof(Visited));

	BFS(1);

	cout << Visited[100] << "\n";

	return 0;
}

/*
이 문제를 통해 BFS가 최단경로를 보장한다는 것을 더 잘 이해하게 되었다.
원래 알고 있긴 했지만 전까지는 내가 검증을 못했어서 확신하지 못했는데 이 문제를 통해서 확신하게 되었다.
만약 뱀을 밟아서 뒤로 돌아갔을때 그 점이 처음 방문한 점이어도 나중에 그냥 주사위만 굴려서 다시한번 방문했을때의 주사위를 굴린 횟수보다 더 크지 않다는 것을 알게되어서 BFS가 최단경로를 보장한다는 것을 확신하게 되었다.
앞으로 BFS문제를 풀때 최단경로를 보장해준다는 점을 전보다 더 잘 활용해서 더 쉽게 만들 수 있을 것 같다.
*/
