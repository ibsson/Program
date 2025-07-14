#include <iostream>
using namespace std;

int N, M;
int arr[10];

void Back_Tracking(int X, int cnt) {
	arr[cnt] = X;

	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (i >= X) {
			Back_Tracking(i, cnt + 1);
		}
	}
 }

int main(void) {

	cin >> N >> M;

	Back_Tracking(0, 0);

	return 0;
}
