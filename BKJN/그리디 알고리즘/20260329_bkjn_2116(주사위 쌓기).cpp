#include <iostream>
using namespace std;

int opposite[6] = { 5, 3, 4, 1, 2, 0 };
int dice[10001][6];
int N;

int getMaxSide(int diceIdx, int bottomIdx, int topIdx) {
    int maxVal = 0;
    for (int i = 0; i < 6; i++) {
        if (i == bottomIdx || i == topIdx) continue;
        maxVal = max(maxVal, dice[diceIdx][i]);
    }
    return maxVal;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dice[i][j];
        }
    }

    int totalMax = 0;

    for (int i = 0; i < 6; i++) {
        int currentSum = 0;
        int bottomIdx = i;
        int topIdx = opposite[i];

        currentSum += getMaxSide(0, bottomIdx, topIdx);

        int prevTopValue = dice[0][topIdx];

        for (int d = 1; d < N; d++) {
            int currentBottomIdx, currentTopIdx;

            for (int j = 0; j < 6; j++) {
                if (dice[d][j] == prevTopValue) {
                    currentBottomIdx = j;
                    break;
                }
            }
            currentTopIdx = opposite[currentBottomIdx];

            currentSum += getMaxSide(d, currentBottomIdx, currentTopIdx);

            prevTopValue = dice[d][currentTopIdx];
        }

        totalMax = max(totalMax, currentSum);
    }

    cout << totalMax << "\n";

    return 0;
}
