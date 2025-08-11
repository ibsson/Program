#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
#define INF 1000000000

int N, M;
char maze[MAX][MAX];
int dp[MAX][MAX];
int dir[4][2] = { {1, 0} ,{0, 1}, { -1, 0 }, {0, -1} };

void djikstra(int r, int c) {
    dp[r][c] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, { r, c } });

    while (!pq.empty()) {
        int cur_cnt = pq.top().first;
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        pq.pop();

        if (dp[cur_r][cur_c] < cur_cnt) continue;

        for (int i = 0; i < 4; i++) {
            int next_cnt;
            int next_r = cur_r + dir[i][0];
            int next_c = cur_c + dir[i][1];

            if (next_r >= 0 && next_r < M && next_c >= 0 && next_c < N) {
                if (maze[next_r][next_c] == 0) {
                    next_cnt = dp[cur_r][cur_c];
                }
                else {
                    next_cnt = dp[cur_r][cur_c] + 1;
                }

                if (dp[next_r][next_c] > next_cnt) {
                    pq.push({ next_cnt, {next_r, next_c} });
                    dp[next_r][next_c] = next_cnt;
                }
            }
        }
    }
}

int main(void) {

	cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char ch;
            cin >> ch;
            maze[i][j] = ch - '0';
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = INF;
        }
    }

    djikstra(0, 0);

    cout << dp[M - 1][N - 1];

	return 0;
}

/*
다이크스트라 알고리즘과 우선순위큐를 이용해서 만들었다.
너무 어려워서 다른사람의 코드를 참고했다.
다이크스트라 알고리즘을 처음으로 활용했던 문제였다.
앞으로도 이런 문제가 나오면 쉽게 활용할 수 있도록 이 알고리즘을 완벽히 이해해야겠다.
*/
