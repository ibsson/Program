#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100002

int cnt;
int student[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int cur) {
	int next = student[cur];
	visited[cur] = true;

	if (!visited[next]) {
		dfs(next);
	}
	else if (!done[next]) {
		for (int i = next; i != cur; i = student[i]) {
			done[i] = true;
			cnt++;
		}
		cnt++;
	}
	done[cur] = true;
}

int main() {

	int T = 0, n = 0;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}

		cout << n - cnt << "\n";

		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
	}

	return 0;
}
