#include <iostream>
using namespace std;

#define MAX 1500002

int N, result;
int T[MAX], P[MAX], dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N + 1; i++) {
        result = max(result, dp[i]);

        if (i + T[i] <= N + 1) {
            dp[i + T[i]] = max(dp[i + T[i]], result + P[i]);
        }
    }

    cout << result << "\n";
    return 0;
}
