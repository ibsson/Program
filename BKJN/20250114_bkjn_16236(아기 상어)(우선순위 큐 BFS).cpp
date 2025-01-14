#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M, ans;
int cursize = 2, cur_y, cur_x, ate;
// 현재 상어의 크기, 상어의 위치, 상어가 먹은 물고기의 개수
int board[20][20], visited[20][20];
int dy[4] = { -1,0,0,1 }, dx[4] = { 0,-1,1,0 };
int BFS();

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				cur_y = i;
				cur_x = j;
				board[i][j] = 0;
				// 나중에 상어가 있는 자리로도 이동할 수 있도록 0으로 바꿔줌
			}
		}
	}

	while (1) {
		int sec = BFS();	// 상어가 먹이로 이동하는데 걸린 시간
		ans += sec;	// 더해줌
		if (!sec) break;	// 먹이로 이동하지 못했다면 반복문을 끝냄
	}

	cout << ans;
}

int BFS() {

	memset(visited, 0, sizeof(visited));
	
	int dist = 0;

	queue<pair<int, int>> q;
	// 상어의 이동 경로를 저장한 큐
	priority_queue<pair< int, int >, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// 상어가 먹을 수 있는 물고기의 위치
	// pq에는 먹을 수 있는 물고기까지의 거리가 최단 거리인 것만 들어감
	q.push({ cur_y,cur_x });
	visited[cur_y][cur_x] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visited[y][x] == dist) break;	// 최단 거리에 있는 물고기를 모두 찾았을 때

		for (int i = 0; i < 4; i++) {
			int n_y = y + dy[i];
			int n_x = x + dx[i];

			if (n_y < 0 || n_y >= N || n_x < 0 || n_x >= N) continue;
			if (visited[n_y][n_x] != 0) continue;

			if (!board[n_y][n_x] || board[n_y][n_x] == cursize) {
				// 0이거나 자기 자신과 같은 크기인 곳은 지나갈 수 있음
				q.push({ n_y,n_x });
				visited[n_y][n_x] = visited[y][x] + 1;
			}
			else if (board[n_y][n_x] < cursize) {
				// (ny,nx) 위치에 먹을 수 있는 물고기가 있을 때
				if (!dist) ate++;	// 거리가 확정났다면 먹은 개수를 늘리지 않음

				visited[n_y][n_x] = visited[y][x] + 1;
				dist = visited[n_y][n_x];	// 최소 거리 확정
				pq.push({ n_y,n_x });	// 우선순위 큐에 넣음
			}
		}
	}

	if (pq.empty()) return 0;

	cur_y = pq.top().first;
	cur_x = pq.top().second;
	// 우선 순위에서 가장 위이면서 왼쪽에 위치한 좌표를 뽑고
	// 해당 위치를 다음번 아기 상어의 시작 위치로 지정
	board[cur_y][cur_x] = 0;	// 해당 위치의 먹이를 먹었으므로 0으로 만듦

	if (ate == cursize) {
		// 먹은 횟수가 아기 상어의 크기와 같을 때
		cursize++;
		ate = 0;
	}

	return visited[cur_y][cur_x] - 1;	// 이동 횟수 리턴
}

/*
도저히 모르겠어서 구글링을 해서 풀었다.
이 문제를 풀면서 BFS에 대해서 더 깊게 이해하게 되었고, 우선순위 큐의 작동 방식을 이해하게 되었다.
BFS를 풀면서 우선순위큐를 이런식으로 활용할 수 있다는 것을 알게되었다.
앞으로 문제를 풀때 자주 사용할 것 같으니 잘 익혀놔야겠다.
*/
