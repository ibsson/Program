#include <iostream>
#define MAX 51
using namespace std;

string str[MAX];
bool visited[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int N, M;
bool isCycle = false;

void DFS(int y, int x, int py, int px, char dot) {
    if (isCycle) return;

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (str[ny][nx] != dot) continue;

        if (!visited[ny][nx]) {
            DFS(ny, nx, y, x, dot);
        }
        else if (!(ny == py && nx == px)) {
            isCycle = true;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                DFS(i, j, -1, -1, str[i][j]);
                if (isCycle) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";

    return 0;
}

/*
#include <iostream>
#include <string.h>
using namespace std;

int N, M;
int chk;
int start_y;
int start_x;
char Board[51][51];
int Visited[51][51];
int Move[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

void DFS(int y, int x, int cnt);

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> Board[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Visited[i][j] == 0) {
				start_y = i;
				start_x = j;
				DFS(i, j, 0);

				if (chk == 1) {
					cout << "Yes\n";
					return 0;
				}

				memset(Visited, 0, sizeof(Visited));
			}
		}
	}

	if (chk == 0) cout << "No\n";

	return 0;
}

void DFS(int y, int x, int cnt) {

	for (int i = 0; i < 4; i++) {
		int _y = y + Move[i][0];
		int _x = x + Move[i][1];

		if (cnt <= 1) Visited[start_y][start_x] = 1;
		else Visited[start_y][start_x] = 0;

		if (_y >= 0 && _y < N && _x >= 0 && _x < M && Board[_y][_x] == Board[y][x] && Visited[_y][_x] == 0) {
			if (_y == start_y && _x == start_x) {
				chk = 1;
				return;
			}
			Visited[_y][_x] = 1;
			DFS(_y, _x, cnt + 1);
			Visited[_y][_x] = 0;
		}
	}
}

/*
이 문제는 DFS를 사용해서 풀었다.
DFS를 사용해 인접한 점이 같은 색깔이면 그 점으로 이동하고, 같은방식으로 계속해서 탐색한 후 만약 이동한 점이 출발점이랑 같은 인덱스라면 사이클을 형성하는 것으로 생각하고 풀었다.
생각한대로 잘 풀려서 좋았다.
더 깔끔하고 좋은 풀이가 있을 것 같다.
한번 찾아보고 공부해봐야겠다.
*/
*/
