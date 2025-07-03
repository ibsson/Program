#include <iostream>
using namespace std;

int N;
int arr[10001];
int used[10001];

void DFS(int cnt);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	DFS(0);

	return 0;
}

void DFS(int cnt) {

	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			used[i] = 1;
			arr[cnt] = i;
			DFS(cnt + 1);
			used[i] = 0;
		}
	}
}

/*
이 문제에서 계속 시간초과가 나서 문제가 뭘까 생각을 해보다가 cout에 endl이 아니라 \n을 사용하고,
메인함수 앞에 
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

이걸 붙이니까 풀렸다. 
저번에도 이런문제가 발생해서 이 방법을 사용해서 풀렸던 문제가 있어서 빠르게 해결할 수 있었던 것 같다.
*/
