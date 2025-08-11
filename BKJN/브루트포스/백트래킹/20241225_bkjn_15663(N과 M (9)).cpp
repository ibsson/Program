#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int arr[9];
bool Visited[9];

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
        if (!Visited[i] && num[i] != last) {
            arr[cnt] = num[i];
            last = arr[cnt];
            Visited[i] = 1;
            Back_Tracking(cnt + 1);
            Visited[i] = 0;
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

/*
수열의 마지막 값과 새로 추가되는 값이 같을때 중복되는 수열이 만들어지므로 num[i] != last 라는 조건문을 만들어주고 백트래킹으로 답을 찾아나가는 방식으로 코드를 만들었다.
*/
