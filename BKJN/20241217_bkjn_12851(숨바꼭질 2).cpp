#include <iostream>
#include <queue>
using namespace std;

int N, K;
int Visited[100002];
int first = 1;
int result, cnt;

void BFS();

int main(void) {

	cin >> N >> K;

	BFS();

	cout << result << "\n";
	cout << cnt << "\n";

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
		Visited[X] = 1;

		if (!first && X == K && result == time) {
			cnt++;
		}

		if (first && X == K) {
			result = time;
			first = 0;
			cnt++;
		}

		if (X - 1 >= 0 && X - 1 <= 100000) {
			if (!Visited[X - 1]) {
				q.push({ X - 1, time + 1 });
			}
		}
		if (X + 1 >= 0 && X + 1 <= 100000) {
			if (!Visited[X + 1]) {
				q.push({ X + 1, time + 1 });
			}
		}
		if (X * 2 >= 0 && X * 2 <= 100000) {
			if (!Visited[X * 2]) {
				q.push({ X * 2, time + 1 });
			}
		}
	}
}
