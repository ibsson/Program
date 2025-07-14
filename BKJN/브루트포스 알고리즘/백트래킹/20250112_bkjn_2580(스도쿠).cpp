#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> pos;
int z_cnt = 0, chk = 0;

bool check(int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == val) return false;
        
        if (sudoku[i][col] == val) return false;
    }

    int part_row = row / 3;
    int part_col = col / 3;
    part_row *= 3;
    part_col *= 3;

    for (int i = part_row; i < part_row + 3; i++) {
        for (int j = part_col; j < part_col + 3; j++) {
            if (sudoku[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int cnt) {
    if (chk) return;

    if (cnt == z_cnt) {
        chk = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }

    int row_p = pos[cnt].first;
    int col_p = pos[cnt].second;

    for (int i = 1; i <= 9; i++) {
        if (check(row_p, col_p, i)) {
            sudoku[row_p][col_p] = i;
            dfs(cnt + 1);
            sudoku[row_p][col_p] = 0;
        }
    }
}

int main() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];

            if (sudoku[i][j] == 0) {
                pos.push_back({ i, j });
                z_cnt++;
            }
        }
    }

    dfs(0);
    return 0;
}
