#include <iostream>
#include <queue>
using namespace std;

int N, K;
int Visited[100002];

void BFS();

int main(void) {

	cin >> N >> K;

	BFS();

	return 0;
}

void BFS() {
	queue <pair<int, int>> q;
	
	q.push({ N, 0 });
	Visited[N] = 1;

	while (!q.empty()) {
		int X = q.front().first;	
		int time = q.front().second;
		q.pop();

		if (X == K) {
			cout << time << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		if ((X - 1) >= 0 && (X - 1) <= 100000) {
			if (!Visited[X - 1]) {
				q.push({ X - 1, time + 1 });
				Visited[X - 1] = 1;
			}
		}
		if ((X + 1) >= 0 && (X + 1) <= 100000) {
			if (!Visited[X + 1]) {
				q.push({ X + 1, time + 1 });
				Visited[X + 1] = 1;
			}
		}
		if ((X * 2) >= 0 && (X * 2) <= 100000) {
			if (!Visited[X * 2]) {
				q.push({ X * 2, time + 1 });
				Visited[X * 2] = 1;
			}
		}
	}
}

/*
이 문제는 잘 풀었지만 방문한점을 체크를 안해줘서 메모리가 엄청나게 커져 계속 틀렸었다.
BFS, DFS에서 중요한 방문한점 체크하기를 앞으로 까먹지 않고 명심하고 실수하지 않고 풀 수 있을 것 같다.
*/
