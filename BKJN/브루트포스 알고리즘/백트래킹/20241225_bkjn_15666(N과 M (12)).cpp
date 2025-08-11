#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int arr[9];

void Back_Tracking(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        return;
    }

    int last = 0;

    for (int i = 0; i < N; i++) {
        if (num[i] >= arr[cnt - 1]) {
            if (num[i] != last) {
                arr[cnt] = num[i];
                last = arr[cnt];
                Back_Tracking(cnt + 1);
            }
        }
    }

    return;
}

int main(void) {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);

    Back_Tracking(0);

    return 0;
}
