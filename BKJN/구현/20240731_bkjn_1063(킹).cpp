#include <stdio.h>
#include <string.h>

void convert_position(char* pos, int* row, int* col) {
    *col = pos[0] - 'A';
    *row = pos[1] - '1';
}

void convert_back(int row, int col, char* pos) {
    pos[0] = 'A' + col;
    pos[1] = '1' + row;
    pos[2] = '\0';
}

void move(int* row, int* col, const char* move) {
    if (strcmp(move, "R") == 0) {
        *col += 1;
    }
    else if (strcmp(move, "L") == 0) {
        *col -= 1;
    }
    else if (strcmp(move, "B") == 0) {
        *row -= 1;
    }
    else if (strcmp(move, "T") == 0) {
        *row += 1;
    }
    else if (strcmp(move, "RT") == 0) {
        *col += 1;
        *row += 1;
    }
    else if (strcmp(move, "LT") == 0) {
        *col -= 1;
        *row += 1;
    }
    else if (strcmp(move, "RB") == 0) {
        *col += 1;
        *row -= 1;
    }
    else if (strcmp(move, "LB") == 0) {
        *col -= 1;
        *row -= 1;
    }
}

int main(void) {
    char king_pos[3], stone_pos[3], direction[3];
    int n = 0;

    scanf("%s", king_pos, sizeof(king_pos));
    scanf("%s", stone_pos, sizeof(stone_pos));
    scanf("%d", &n);

    int king_row, king_col, stone_row, stone_col;
    convert_position(king_pos, &king_row, &king_col);
    convert_position(stone_pos, &stone_row, &stone_col);

    for (int i = 0; i < n; ++i) {
        scanf("%s", direction, sizeof(direction));

        int new_king_row = king_row, new_king_col = king_col;
        move(&new_king_row, &new_king_col, direction);

        if (new_king_row < 0 || new_king_row >= 8 || new_king_col < 0 || new_king_col >= 8) {
            continue;
        }

        if (new_king_row == stone_row && new_king_col == stone_col) {
            int new_stone_row = stone_row, new_stone_col = stone_col;
            move(&new_stone_row, &new_stone_col, direction);

            if (new_stone_row < 0 || new_stone_row >= 8 || new_stone_col < 0 || new_stone_col >= 8) {
                continue;
            }

            stone_row = new_stone_row;
            stone_col = new_stone_col;
        }

        king_row = new_king_row;
        king_col = new_king_col;
    }

    convert_back(king_row, king_col, king_pos);
    convert_back(stone_row, stone_col, stone_pos);

    printf("%s\n%s\n", king_pos, stone_pos);

    return 0;
}
