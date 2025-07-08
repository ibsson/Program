#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 21

int grid[MAX][MAX];
bool visited[MAX][MAX];
int people[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 격자 인구 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 1000000000;

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    if ((y - d1) <= 0 || (y + d2) > N || (x + d1 + d2) > N) continue;

                    memset(visited, false, sizeof(visited));
                    memset(people, 0, sizeof(people));

                    //경계선
                    for (int i = 0; i <= d1; i++) {
                        visited[x + i][y - i] = true;
                    }
                    for (int i = 0; i <= d2; i++) {
                        visited[x + i][y + i] = true;
                    }
                    for (int i = 0; i <= d2; i++) {
                        visited[x + d1 + i][y - d1 + i] = true;
                    }
                    for (int i = 0; i <= d1; i++) {
                        visited[x + d2 + i][y + d2 - i] = true;
                    }

                    //내부 채우기
                    for (int i = x + 1; i < (x + d1 + d2); i++) {
                        if (i < 1 || i > N) continue;

                        int min_c = 1000, max_c = 0;
                        
                        for (int j = 1; j <= N; j++) {
                            if (visited[i][j]) {
                                min_c = min(min_c, j);
                                max_c = max(max_c, j);
                            }
                        }

                        for (int j = min_c; j <= max_c; j++) {
                            visited[i][j] = true;
                        }
                    }

                    for (int r = 1; r <= N; r++) {
                        for (int c = 1; c <= N; c++) {
                            if (visited[r][c]) {
                                people[4] += grid[r][c];
                                continue;
                            }

                            if (r < x + d1 && c <= y) people[0] += grid[r][c];
                            if (r <= x + d2 && c > y) people[1] += grid[r][c];
                            if (r >= x + d1 && c < y - d1 + d2) people[2] += grid[r][c];
                            if (r > x + d2 && c >= y - d1 + d2) people[3] += grid[r][c];
                        }
                    }

                    int _max = -1, _min = 100000;
                    for (int i = 0; i < 5; i++) {
                        _max = max(_max, people[i]);
                        _min = min(_min, people[i]);
                    }

                    res = min(res, _max - _min);
                }
            }
        }
    }
    cout << res << '\n';

    return 0;
}
