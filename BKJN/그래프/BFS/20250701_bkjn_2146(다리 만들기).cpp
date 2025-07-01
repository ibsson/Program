#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100

int map[MAX][MAX];
bool visited[MAX][MAX];
int num[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int res = INT_MAX;

// 대륙 번호 매기는 BFS
void BFS_1(int i, int j, int cnt, int N) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(i, j));
    num[i][j] = cnt;
    visited[i][j] = true;

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
                num[ny][nx] = cnt;
                visited[ny][nx] = true;
                Q.push({ ny, nx });
            }
        }
    }
}

// 다리 만드는 BFS
void BFS_2(int N, int land) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    queue <pair<pair<int, int>, int>> Q; //좌표, 길이

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (num[i][j] == land) {
                Q.push({ {i, j}, 0 });
            }
        }
    }

    while (!Q.empty()) {
        int y = Q.front().first.first, x = Q.front().first.second;
        int c = Q.front().second;
        Q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (visited[ny][nx]) continue;

            if (num[ny][nx] != land && num[ny][nx] != 0) {
                if (res > c) res = c;
            }

            if (num[ny][nx] == 0) {
                visited[ny][nx] = true;
                Q.push({ {ny, nx}, c + 1 });
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 지도 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 1;

    // 대륙 번호 매기기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                BFS_1(i, j, cnt, N);
                cnt++;
            }
        }
    }

    //다리 만드는 BFS호출
    for (int i = 1; i < cnt; i++) {
        BFS_2(N, i);
    }

    // 결과 출력
    cout << res << "\n";

    return 0;
}
