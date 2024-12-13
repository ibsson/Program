#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int S;
int Visited[1002][1002];

void BFS();

int main(void) {

	cin >> S;
	
	BFS();

	return 0;
}

void BFS() {
	queue<tuple<int, int, int>> q;

	q.push(make_tuple(1, 0, 0));
	Visited[1][0] = 1;

	while (!q.empty()) {
		int screen = get<0>(q.front());
		int clip = get<1>(q.front());
		int time = get<2>(q.front());
		q.pop();

		if (screen == S) {
			cout << time << "\n";
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		if (screen >= 0 && screen <= 1000) {
			if (!Visited[screen][screen]) {
				q.push(make_tuple(screen, screen, time + 1));
				Visited[screen][clip + screen] = 1;
			}
		}
		if (screen + clip >= 0 && screen + clip <= 1000) {
			if (!Visited[screen + clip][clip]) {
				q.push(make_tuple(screen + clip, clip, time + 1));
				Visited[screen + clip][clip] = 1;
			}
		}
		if (screen - 1 >= 0 && screen - 1 <= 1000) {
			if (!Visited[screen - 1][clip]) {
				q.push(make_tuple(screen - 1, clip, time + 1));
				Visited[screen - 1][clip] = 1;
			}
		}
	}
}

/*
BFS, DFS문제는 방문한점을 체크해주는것이 정말 중요하다고 생각이 드는 문제였다.
*/
