#include <iostream> 
#include <string.h>
#include <queue>

using namespace std;

char mat[9][9];
int isVisited[9][9];
int dir[9][2] = { {0,0}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1},{1,-1} };

bool isValid(int y, int x) {
    return (y >= 1 && y <= 8) && (x >= 1 && x <= 8);
}

void down_walls() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 1; j <= 8; j++) {
            mat[i + 1][j] = mat[i][j];
        }
    }
}


bool bfs() {

    queue<pair<int, int> > q;
    q.push({ 8,1 });
    isVisited[8][1] = 1;

    while (!q.empty()) {
        memset(isVisited, 0, sizeof(isVisited));
        int size = q.size();

        while (size--) {
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();

            if (mat[cy][cx] == '#') continue;

            for (int d = 0; d < 9; d++) {
                int ny = cy + dir[d][0];
                int nx = cx + dir[d][1];

                if (ny == 1 && nx == 8) return true;

                if (!isValid(ny, nx)) continue;
                if (mat[ny][nx] == '#') continue;
                if (isVisited[ny][nx]) continue;

                isVisited[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }

        down_walls();
    }

    return false;
}


int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cin >> mat[i][j];
        }
    }
    for (int j = 1; j <= 8; j++) mat[0][j] = '.';

    if (bfs()) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}

/*
#include <iostream>
#include <queue>
using namespace std;

char map[8][8];
char maze[9][8][8];
int dir[9][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 0} };

int bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push({ {7, 0}, 0 });

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (cnt == 9) return 1;

		if (maze[cnt][row][col] == '.') {
			for (int i = 0; i < 9; i++) {
				int n_row = row + dir[i][0];
				int n_col = col + dir[i][1];

				if (n_row >= 0 && n_row < 8 && n_col >= 0 && n_col < 8) {
					if (maze[cnt][n_row][n_col] != '#') {
						q.push({ {n_row, n_col}, cnt + 1 });
					}
				}
			}
		}
	}

	return 0;
}

int main(void) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < 8; k++) {
				maze[i][j][k] = '.';
			}
		}

		for (int j = i; j < 8; j++) {
			for (int l = 0; l < 8; l++) {
				maze[i][j][l] = map[j - i][l];
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}
*/
