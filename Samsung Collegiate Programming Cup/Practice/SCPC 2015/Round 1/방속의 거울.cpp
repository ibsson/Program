#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1004
char arr[MAX][MAX];
bool visited[MAX][MAX];
bool chk = false;
int N;
int res;

//우 0 하 1 좌 2 상 3
void DFS(int y, int x, int dir, int cnt) {
	if (chk) return;

	if (y < 0 || y >= N || x < 0 || x >= N) {
		chk = true;
		res = cnt;
		return;
	}

	if (dir == 0) {
		if (arr[y][x] == '0') {
			visited[y][x] = true;
			DFS(y, x + 1, 0, cnt);
		}
		else if (arr[y][x] == '1') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y - 1, x, 3, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y - 1, x, 3, cnt + 1);
			}
		}
		else if (arr[y][x] == '2') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y + 1, x, 1, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y + 1, x, 1, cnt + 1);
			}
		}
	}
	else if (dir == 1) {
		if (arr[y][x] == '0') {
			visited[y][x] = true;
			DFS(y + 1, x, 1, cnt);
		}
		else if (arr[y][x] == '1') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y, x - 1, 2, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y, x - 1, 2, cnt + 1);
			}
		}
		else if (arr[y][x] == '2') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y, x + 1, 0, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y, x + 1, 0, cnt + 1);
			}
		}
	}
	else if (dir == 2) {
		if (arr[y][x] == '0') {
			visited[y][x] = true;
			DFS(y, x - 1, 2, cnt);
		}
		else if (arr[y][x] == '1') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y + 1, x, 1, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y + 1, x, 1, cnt + 1);
			}
		}
		else if (arr[y][x] == '2') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y - 1, x, 3, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y - 1, x, 3, cnt + 1);
			}
		}
	}
	else if (dir == 3) {
		if (arr[y][x] == '0') {
			visited[y][x] = true;
			DFS(y - 1, x, 3, cnt);
		}
		else if (arr[y][x] == '1') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y, x + 1, 0, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y, x + 1, 0, cnt + 1);
			}
		}
		else if (arr[y][x] == '2') {
			if (visited[y][x]) {
				visited[y][x] = true;
				DFS(y, x - 1, 2, cnt);
			}
			else {
				visited[y][x] = true;
				DFS(y, x - 1, 2, cnt + 1);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> arr[j];
		}

		DFS(0, 0, 0, 0);

		cout << "Case #" << i << '\n';
		cout << res << '\n';
		res = 0, chk = false;

		memset(visited, false, sizeof(visited));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}
