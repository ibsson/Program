#include <iostream>
using namespace std;

#define MAX 1000002
#define INF 1000000002

int stone[MAX];
int DP[MAX];

int getResult(int N, int K) {
    DP[0] = 0;
    int left = 0;

    for (int i = 1; i <= N; i++) {
        DP[i] = INF;

        while (left < i && stone[left] + K < stone[i]) {
            left++;
        }

        if (left < i && DP[left] != INF) {
            DP[i] = DP[left] + 1;
        }
    }

    return DP[N];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N;

        stone[0] = 0;

        for (int i = 1; i <= N; i++) {
            cin >> stone[i];
        }

        cin >> K;

        int result = getResult(N, K);

        static int case_num = 1;
        cout << "Case #" << case_num++ << '\n';
        if (result == INF) cout << "-1\n";
        else cout << result << '\n';
    }

    return 0;
}
