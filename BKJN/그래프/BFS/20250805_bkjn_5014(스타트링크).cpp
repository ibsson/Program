#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

struct Node {
	int floor, dist;
};

bool visited[MAX];

int BFS(int f, int s, int g, int u, int d) {
	queue <Node> q;
	visited[s] = true;
	q.push({s, 0});

	while (!q.empty()) {
		int idx = q.front().floor, dist = q.front().dist;
		q.pop();
		
		if (idx == g) {
			return dist;
		}

		if ((idx - d) >= 1) {
			if (!visited[idx - d]) {
				q.push({ idx - d , dist + 1 });
				visited[idx - d] = true;
			}
		}

		if ((idx + u) <= f) {
			if (!visited[idx + u]) {
				q.push({ idx + u, dist + 1 });
				visited[idx + u] = true;
			}
		}
	}

	return -1;
}

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	int res = BFS(F, S, G, U, D);

	if (res == -1) {
		cout << "use the stairs\n";
	}
	else {
		cout << res << '\n';
	}

	return 0;
}
