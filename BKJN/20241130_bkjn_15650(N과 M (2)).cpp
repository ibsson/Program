#include <iostream>
using namespace std;

int N, M;
int arr[9];

void DFS(int idx, int depth) {

    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else {
        for (int i = idx; i <= N; i++) {
            arr[depth] = i;
            DFS(i + 1, depth + 1);
        }
    }
}

int main(void) {

    cin >> N >> M;

    DFS(1, 0);

    return 0;
}
