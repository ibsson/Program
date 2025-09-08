#include <iostream>
using namespace std;

int M; //값
int c[5] = { 1, 5, 10, 20, 25 }; //동전값

void greedyChange() {
	int a = M;
	int arr[5] = { 0 };

	while (a > 0) {
		for (int i = 4; i >= 0; i--) {
			if (a >= c[i]) {
				a = a - c[i]; //남은 값에서 동전의 값만큼 빼기
				arr[i] = arr[i] + 1; //동전 개수 추가
				break;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void betterGreedyChange() {
	int arr[5] = { 0 };
	int a = M;

	for (int i = 4; i >= 0; i--) {
		arr[i] = (a / c[i]); //남은 값에서 동전의 값만큼 나누기 (동전의 개수 구하기)
		a -= (c[i] * arr[i]); //남은 값에서 (동전값 * 동전개수) 만큼 빼줌
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin >> M;

	greedyChange();
	betterGreedyChange();

	return 0;
}
