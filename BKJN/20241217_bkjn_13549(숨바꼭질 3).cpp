#include <iostream>
#include <queue>
using namespace std;

int N, K;
int Visited[100002];
int Min = 1000000;

void BFS();

int main(void) {

	cin >> N >> K;

	BFS();

	cout << Min << "\n";

	return 0;
}

void BFS() {
	queue <pair<int, int>> q;

	q.push({ N, 0 });
	Visited[N] = 1;

	while (!q.empty()) {
		int X = q.front().first;
		int time = q.front().second;
		Visited[X] = 1;
		q.pop();

		if (Min < time) continue;

		if (X == K && Min > time) {
			Min = time;
		}

		if ((X - 1) >= 0 && (X - 1) <= 100000) {
			if (!Visited[X - 1]) {
				q.push({ X - 1, time + 1 });
			}
		}
		if ((X + 1) >= 0 && (X + 1) <= 100000) {
			if (!Visited[X + 1]) {
				q.push({ X + 1, time + 1 });
			}
		}
		if ((X * 2) >= 0 && (X * 2) <= 100000) {
			if (!Visited[X * 2]) {
				q.push({ X * 2, time });
			}
		}
	}
}
