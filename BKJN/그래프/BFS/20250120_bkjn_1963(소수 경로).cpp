#include <iostream>
#include <queue>
#include <string.h>
#include <string>
using namespace std;

#define MAX 10000

bool eratos[MAX];
bool visited[MAX];

void makeEratos() {
	memset(eratos, true, sizeof(eratos));

	for (int i = 2; i < MAX; i++) {
		for (int j = 2; i * j < MAX; j++) {
			eratos[i * j] = false;
		}
	}
}

int bfs(int s, int f) {
	queue <pair<int, int>> q;
	q.push({s, 0});
	visited[s] = 1;

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == f) return cnt;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				string str = to_string(num);
				str[i] = j + '0';

				int tmp = stoi(str);

				if (tmp >= 10000 || tmp < 1000) continue;

				if (eratos[tmp] == 1 && visited[tmp] == false) {
					q.push({ tmp, cnt + 1 });
					visited[tmp] = true;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	makeEratos();

	int T = 0;

	cin >> T;

	int from, to;

	for (int i = 0; i < T; i++) {
		memset(visited, false, sizeof(visited));
		
		cin >> from >> to;

		cout << bfs(from, to) << "\n";
	}

	return 0;
}
