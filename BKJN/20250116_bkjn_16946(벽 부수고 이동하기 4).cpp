#include <iostream>
#include <queue>
using namespace std;

#define MAX 1002

int N, M;
int map[MAX][MAX];
bool zero_visited[MAX][MAX];
bool one_visited[MAX][MAX];
int result[MAX][MAX];
queue <pair<int, int>> idx;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int bfs(int s_r, int s_c) {
	queue <pair<int, int>> q;
	q.push({ s_r, s_c });
	zero_visited[s_r][s_c] = true;

	int cnt = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int n_r = r + dy[i];
			int n_c = c + dx[i];

			if (n_r >= 0 && n_r < N && n_c >= 0 && n_c < M) {
				if (!zero_visited[n_r][n_c] && map[n_r][n_c] == 0) {
					q.push({ n_r, n_c });
					zero_visited[n_r][n_c] = true;
					cnt++;
				}
				else if (map[n_r][n_c] == 1 && !one_visited[n_r][n_c]) {
					idx.push({ n_r, n_c });
					one_visited[n_r][n_c] = true;
				}
			}
		}
	}

	return cnt;
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char x = 0;
			cin >> x;
			map[i][j] = x - '0';

			if (map[i][j] == 1) {
				result[i][j] = map[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && !zero_visited[i][j]) {
				int zero_cnt = bfs(i, j);

				while (!idx.empty()) {
					result[idx.front().first][idx.front().second] += zero_cnt;
					one_visited[idx.front().first][idx.front().second] = false;
					idx.pop();
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (result[i][j] != 0) cout << result[i][j] % 10;
			else cout << result[i][j];
		}
		cout << "\n";
	}

	return 0;
}

/*
1이 나올때마다 bfs를 실행해서 풀었더니 시간초과가 나왔다.
방법을 찾아보니 0을 기준으로 푸는것이 더 효율적이었다.
0이 이어져있는 곳을 bfs를 통해 그룹화하고, 그 bfs에서 1을 마주칠때마다 인덱스를 저장 후, bfs에서 나온 0의 개수들을 그 1의 인덱스에 저장해주는 방식으로 풀었다.
어려운 문제는 그냥 직관적으로 풀면 안되고, 좀 더 효율적인 방법이 무엇인지 생각해야 한다는 것을 많이 느꼈던 문제였던 것 같다.
어려운 문제를 풀때는 직관적으로 보이는 방법 말고, 다른 방법으로 더 효율적일 수 있는 방법을 생각해봐야겠다.
그리고 항상 문제를 풀때 생각한 방법이 효율적인지, 더 최적화 시킬 수 있는 방법이 뭔지 생각해보고 푸는 습관을 들여야겠다.
*/
