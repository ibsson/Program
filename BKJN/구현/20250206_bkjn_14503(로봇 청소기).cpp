#include <iostream>
using namespace std;

#define MAX 51

int N, M, cnt;
int room[MAX][MAX];
bool visited[MAX][MAX];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int r, int c, int d) {
    if (!visited[r][c]) {
        visited[r][c] = true;
        cnt++;
    }

    for (int i = 0; i < 4; i++) {
        d = (d + 3) % 4;
        int n_r = r + dy[d], n_c = c + dx[d];

        if (room[n_r][n_c] == 0 && !visited[n_r][n_c]) {
            dfs(n_r, n_c, d);
            return;
        }
    }

    int back_d = (d + 2) % 4;
    int back_r = r + dy[back_d], back_c = c + dx[back_d];

    if (room[back_r][back_c] == 0) {
        dfs(back_r, back_c, d);
    }
}

int main() {
    int r = 0, c = 0, d = 0;
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    dfs(r, c, d);

    cout << cnt << "\n";

    return 0;
}
