#include <iostream>
#include <vector>
using namespace std;

#define MAX 11

int N, M, H;
int result = 4;
int ver[MAX][31];

bool chkResult() {
    for (int i = 1; i <= N; i++) {
        int cur = i;
        for (int j = 1; j <= H; j++) {
            if (cur < N && ver[cur][j] == 1) cur++;
            else if (cur > 1 && ver[cur - 1][j] == 1) cur--;
        }
        if (cur != i) return false;
    }
    return true;
}

void dfs(int cnt, int x, int y) {
    if (chkResult()) {
        result = min(result, cnt);
        return;
    }
    if (cnt >= 3 || result <= cnt) return;

    for (int i = x; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (ver[j][i] == 1) continue;
            if (ver[j - 1][i] == 1) continue;
            if (ver[j + 1][i] == 1) continue;

            ver[j][i] = 1;
            dfs(cnt + 1, i, j);
            ver[j][i] = 0;
        }
    }
}

int main() {
    cin >> N >> M >> H;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        ver[b][a] = 1;
    }

    dfs(0, 1, 1);

    if (result == 4) cout << "-1\n";
    else cout << result << "\n";

    return 0;
}
