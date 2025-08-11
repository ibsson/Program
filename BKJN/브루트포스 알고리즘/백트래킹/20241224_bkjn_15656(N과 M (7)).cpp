#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[9];
int arr[9];

void Back_Tracking(int idx, int cnt) {
	arr[cnt] = num[idx];

	if (cnt == M) {
		for (int i = 1; i <= M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++) {
		Back_Tracking(i, cnt + 1);
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	sort(num + 1, num + (N + 1));

	Back_Tracking(0, 0);

	return 0;
}
